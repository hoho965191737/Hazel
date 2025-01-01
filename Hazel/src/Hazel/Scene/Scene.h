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

		// ��ʱ
		entt::registry& Reg() { return m_Registry; }


	private:
		entt::registry m_Registry;	// ��������component��entity ������ {entity_id: data},����entity������
	};


}