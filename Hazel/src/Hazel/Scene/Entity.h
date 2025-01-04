#pragma once
#include "Scene.h"
#include "entt.hpp"

namespace Hazel {

	class Entity
	{
	public:
		Entity() = default;	// 默认构造函数
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;	// 复制构造函数

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args) {
			HZ_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");

			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);	// 这里只做转发，并不拆开处理这些参数
		}

		template<typename T>
		T& GetComponent() {
			HZ_CORE_ASSERT(HasComponent<T>(), "Get! Entity does not have component!");

			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponent() {
			return m_Scene->m_Registry.any_of<T>(m_EntityHandle);
		}

		template<typename T>
		void RemoveComponent() {
			HZ_CORE_ASSERT(HasComponent<T>(), "Remove! Entity does not have component!");
			return m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		operator bool() const { return (bool)m_EntityHandle != 0; }

	private:
		entt::entity m_EntityHandle{ 0 };
		Scene* m_Scene = nullptr;	// todo: 后面改成弱引用
	};




}