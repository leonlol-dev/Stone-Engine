
#include "Component.h"


namespace myengine
{
	struct Core;

	///This is the trigger class, when something touches a game object something will happen. 
	struct Trigger : Component
	{
		///OnTick() checks if its colliding with a collider.
		void onTick();

	private:
		friend struct myengine::Core;
	};

}