#pragma once

#include <entt.hpp>
#include "Hazel/Core/Timestep.h"
#include <string>

namespace Hazel {

	class Entity; // ǰ������

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void OnUpdate(Timestep ts);


	private:
		entt::registry m_Registry;	// ��������component��entity ������ {entity_id: data},����entity������

		friend class Entity;
		
	};


}