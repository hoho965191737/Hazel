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
		void OnUpdate(Timestep ts);


	private:
		entt::registry m_Registry;	// 这是所有component和entity 的容器 {entity_id: data},当成entity上下文

		friend class Entity;
		
	};


}