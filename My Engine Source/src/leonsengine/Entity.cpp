#include "Entity.h"
#include "Core.h"
#include "Component.h"
#include "SphereCollider.h"

namespace myengine
{

	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	std::shared_ptr<Transform> Entity::getTransform()
	{
		return transform.lock();
	}
	std::shared_ptr<Component> Entity::getComponent()
	{
		for (size_t co = 0; co < components.size(); co++)
		{
			return components.at(co);

		}
	}
	void Entity::tick()
	{
		for (size_t co = 0; co < components.size(); co++)
		{
			components.at(co)->tick();
		}
	}
	void Entity::display()
	{
		for (size_t co = 0; co < components.size(); co++)
		{
			components.at(co)->display();
		}
	}

	void Entity::begin()
	{
		for (size_t co = 0; co < components.size(); co++)
		{
			components.at(co)->begin();
		}
	}

	void Entity::colliding(std::shared_ptr<SphereCollider> sc)
	{
		for (size_t co = 0; co < components.size(); co++)
		{
			components.at(co)->collision(sc);
		}
	}

}

