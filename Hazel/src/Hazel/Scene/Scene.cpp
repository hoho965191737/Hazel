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
			// todo��MeshComponentΪ�յĻ�������ᱨ������֪��Ϊʲô������
			// EnTT ��������get�������С�����һ��ʹ�á�����һ���ڲ��Ż������ݴ�����ϡ�輯�У���û���������С�Ƚϵ�ʵ�ʴ洢����
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