#include "Trigger.h"
#include "Core.h"
#include "Entity.h"
#include "SphereCollider.h"

namespace myengine
{

	void Trigger::onTick()
	{
		std::shared_ptr<SphereCollider> sc = getEntity()->getComponent<SphereCollider>();

		std::vector<std::shared_ptr<SphereCollider>>& sphereColliders = getCore()->sphereColliders;

		for (size_t ci = 0; ci < sphereColliders.size(); ci++)
		{
			if (sphereColliders.at(ci) == sc) continue;

			if (sc->isColliding(sphereColliders.at(ci)))
			{
				getEntity()->colliding(sphereColliders.at(ci));
				sphereColliders.at(ci)->getEntity()->colliding(sc);
			}
		}
	}

}