#pragma once

#include <memory>
#include "Component.h"


namespace myengine
{
	struct Core;
	struct SphereCollider;

	///This is the sphere collider. It calculates if any game objects are colliding with eachother. 
	///
	///This is done via isColliding() function which is a boolean which returns true if colliding and vice versa.
	///All colliders are in the game engine's core, and onInit() adds the collider to the vector and vice versa for onDestroy().
	struct SphereCollider : Component
	{
		///Register the Sphere Collider to core.
		void onInit();

		///Once destroyed, it deletes itself from core.
		void onDestroy();

		///Checks if the collider is colliding with something, returns a bool.
		///@param _collider Another collider.
		bool isColliding(std::shared_ptr<SphereCollider> _collider);

	private:
		friend struct myengine::Core;
		float m_radius;
	};
}