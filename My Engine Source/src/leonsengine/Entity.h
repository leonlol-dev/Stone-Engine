#pragma once

#include <memory>
#include <vector>
#include "Transform.h"
#include "Exception.h"


namespace myengine
{
	struct Component;
	struct Transform;
	struct Core;
	struct SphereCollider;
	
	///This is the entity class.
	///
	///This is essentially the game object which holds a component. It has multiple ways to add components and get other important class objects such as the core, transform or component.
	///@note You add components to entities. Similar to Unity.

	struct Entity
	{
		//std::shared_ptr<Component> addComponent();

		///Adds a component into a vector of components.
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->self = rtn;
			rtn->entity = self;
		
			components.push_back(rtn);

			rtn->onInit();

			return rtn;
		}

		///Adds a component into a vector of components.
		template <typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>(a);
			rtn->self = rtn;
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInit();

			return rtn;
		}

		///Returns the wanted component.
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t ci = 0; ci < components.size(); ci++)
			{
				std::shared_ptr<T> rtn =
					std::dynamic_pointer_cast<T>(components.at(ci));
				if (rtn)
				{
					return rtn;
				}
			}
			throw Exception("Failed to obtain specified component");
		}

		///Allows entities to access core.
		std::shared_ptr<Core> getCore();

		///Entities to access their transform. 
		std::shared_ptr<Transform> getTransform();

		///Returns an entity's component.
		std::shared_ptr<Component> getComponent();

		///This gets called every tick.
		void tick();

		///This gets called just before glClearScreen for OpenGL purposes. 
		///@note Mainly our Model Renderer and Triangle Renderer use display().
		void display();

		///This get called just before core starts.
		void begin();

		///Whenever a spherecollider collides with a trigger.
		void colliding(std::shared_ptr<SphereCollider> sc);

	private:
		friend struct myengine::Core;
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		std::weak_ptr<Transform> transform;

		;
	};


}