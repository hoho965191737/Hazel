#pragma once

#include <entt.hpp>
#include "Hazel/Core/Timestep.h"

namespace Hazel {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();
		void OnUpdate(Timestep ts);

		// 临时
		entt::registry& Reg() { return m_Registry; }


	private:
		entt::registry m_Registry;	// 这是所有component和entity 的容器 {entity_id: data},当成entity上下文
	};


}