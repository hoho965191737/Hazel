#pragma once

#include <entt.hpp>
#include "Hazel/Core/Timestep.h"
#include <string>

namespace Hazel {

	class Entity; // 前向声明

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void DestroyEntity(Entity entity);
		void OnUpdate(Timestep ts);
		void OnViewportResize(uint32_t width, uint32_t height);
		Entity GetPrimaryCameraEntity();

	private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);

	private:
		entt::registry m_Registry;	// 这是所有component和entity 的容器 {entity_id: data},当成entity上下文
		uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
		friend class Entity;
		friend class SceneHierarchyPanel;
		friend class SceneSerializer;
		
	};


}