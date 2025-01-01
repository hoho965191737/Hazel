#pragma once
#include <glm/glm.hpp>

namespace Hazel {

	struct TransformComponent
	{
		glm::mat4 Transform = { 1.0f };
		TransformComponent() = default;
		TransformComponent(const TransformComponent& transform) = default;
		TransformComponent(const glm::mat4& transform) : Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () const { return Transform; }		// 隐式的强制转换运算符 重载
	};


	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f,1.0f,1.0f,1.0f };
		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4 & color)
			: Color(color) {}
	};

}