#pragma once

#include "Hazel/Renderer/OrthographicCamera.h"
#include "Texture.h"

namespace Hazel {
	class Renderer2D
	{
		// 全部是static方法的class，意味这个class的存储空间为0
		// 目的是为了拥有的数据保持单例
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);	// 正交相机
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