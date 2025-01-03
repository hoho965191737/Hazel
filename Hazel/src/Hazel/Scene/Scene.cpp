#include "hzpch.h"
#include "Scene.h"
#include "Components.h"
#include <glm/glm.hpp>
#include "Hazel/Renderer/Renderer2D.h"

namespace Hazel {

	static void DoMath(const glm::mat4& transform) {

	}

	static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
	{
	}

	Scene::Scene()
	{
#if EXAMPLE_ENTT
		struct MeshComponent{
			bool Data;
			MeshComponent() = default;
		};

		entt::entity entity = m_Registry.create();
		m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
		m_Registry.on_construct<TransformComponent>().connect<&OnTransformConstruct>();
		if (m_Registry.any_of<TransformComponent>(entity))
			TransformComponent& transform = m_Registry.get<TransformComponent>(entity);
		auto view = m_Registry.view<TransformComponent>();
		for (auto entity : view)
		{
			TransformComponent& transform = view.get<TransformComponent>(entity);
		}
		auto group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
		for (auto entity : group)
		{
			// todo：MeshComponent为空的话，这里会报错，不知道为什么！！！
			// EnTT 不允许“get”与零大小的组件一起使用。这是一个内部优化。数据存在于稀疏集中，但没有用于零大小比较的实际存储阵列
			auto& [transform, mesh] = group.get<TransformComponent, MeshComponent>(entity);	
		}
#endif

	}

	Scene::~Scene()
	{
	}

	entt::entity Scene::CreateEntity()
	{
		return m_Registry.create();
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}

}
