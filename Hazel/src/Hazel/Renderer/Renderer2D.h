#pragma once

#include "Hazel/Renderer/OrthographicCamera.h"
#include "Texture.h"

namespace Hazel {
	class Renderer2D
	{
		// ȫ����static������class����ζ���class�Ĵ洢�ռ�Ϊ0
		// Ŀ����Ϊ��ӵ�е����ݱ��ֵ���
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);	// �������
		static void EndScene();

		// Primitives
		// transform
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		
		// texture
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture);
	
	};
}