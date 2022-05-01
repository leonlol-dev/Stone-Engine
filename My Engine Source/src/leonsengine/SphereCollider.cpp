#include "SphereCollider.h"

#include "Core.h"
#include "Entity.h"
#include <glm/glm.hpp>
namespace myengine
{
	void SphereCollider::onInit()
	{
		getCore()->registerCollider(getEntity()->getComponent<SphereCollider>());
		m_radius = 1.0f;
	}
	void SphereCollider::onDestroy()
	{
		getCore()->unregisterCollider(this);
	}
	bool SphereCollider::isColliding(std::shared_ptr<SphereCollider> _collider)
	{
		float distance = glm::distance(getEntity()->getTransform()->getPosition(), _collider->getEntity()->getTransform()->getPosition());
		float rad = m_radius + _collider->m_radius;
		if (distance < rad)
		{
			return true;
		}
		return false;
	}
}