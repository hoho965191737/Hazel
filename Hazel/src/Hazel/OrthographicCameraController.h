#pragma once


#include "Hazel/Renderer/OrthographicCamera.h"
#include "Hazel/Core/Timestep.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"


namespace Hazel {

	// OrthographicCamera �İ�װ��
	class OrthographicCameraController
	{

	public:
		// Ĭ������� �ݺ�ȣ�eg: 16:9�� * 2 units
		OrthographicCameraController(float aspectRatio, bool rotation = false);
		void OnUpdate(Timestep ts);		// ʱ�䲽��
		void OnEvent(Event& e);
		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
	
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	
	private:
		float m_AspectRatio;		// �ݺ��
		float m_ZoomLevel = 1.0f;	// ʵ�����ŵȼ�
		OrthographicCamera m_Camera;
		bool m_Rotation;
		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}