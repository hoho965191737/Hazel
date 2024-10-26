#pragma once

#include "Window.h"

#include "Core.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/ImGui/ImGuiLayer.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
		static Application* s_Instance;

	};

	// to be defined in client
	Application* CreateApplication();

}


