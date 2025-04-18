#pragma once

#include "Hazel/Core/Layer.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel {
	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;
		
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		//virtual void OnImGuiRender() override;
		void Begin();
		void End();

		void SetDarkThemeColors();
		void BlockEvents(bool block) { m_BlockEvents = block; }

	private:
		float m_Time = 0.0f;
		bool m_BlockEvents = true;
	};
}