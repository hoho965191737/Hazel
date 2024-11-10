#include "hzpch.h"
#include "Application.h"

#include <glfw/glfw3.h>

#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Renderer/Buffer.h"


namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		m_Window->SetVSync(false); // 这里设置为false，能看到真实帧速率

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		HZ_CORE_TRACE("{0}", e.ToString());

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}

	}

	void Application::Run() {

		while (m_Running) {
			float time = (float)glfwGetTime();  // Platform::GetTime;这里和glfw进行耦合了
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timestep);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();		// 主要的游戏循环
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}