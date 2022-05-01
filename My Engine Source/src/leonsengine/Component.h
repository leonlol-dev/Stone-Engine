#pragma once

#include <memory>
#include <vector>


namespace myengine
{
	struct Entity;
	struct Core;
	struct Transform;
	struct SphereCollider;

	/// This is the Component similar to Unity's Component. 
	///
	/// In our component class, we have 5 very important functions which are: onInit(), onBegin(), onTick(), onDisplay() and onCollision(). 
	/// As well as getEntity() which gets a specific entity and getCore() which gets our game's core, which handles a lot of things such as
	struct Component
	{
		///Gets the entity the component is attached to.
		std::shared_ptr<Entity> getEntity();

		///Gets the core.
		std::shared_ptr<Core> getCore();

		///Weak pointer to another entity.
		std::weak_ptr<Entity> entity;

		//Weak pointer to itself. 
		std::weak_ptr<Component> self;

	private:

		friend struct myengine::Entity;
		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();
		virtual void onCollision(std::shared_ptr<SphereCollider> sc);
		void tick();
		void display();
		void begin();
		void collision(std::shared_ptr<SphereCollider> sc);
		

	};
}