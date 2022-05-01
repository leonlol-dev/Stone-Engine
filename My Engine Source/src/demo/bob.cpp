#include "bob.h"

void Player::onInit()
{
	tri = getEntity()->addComponent<TriangleRenderer>();
	tri->getEntity()->getTransform()->setPosition(glm::vec3(1.5, 0.5, 0.5));
	
}

void Player::onTick()
{
	tri->getEntity()->getTransform()->setRotation(glm::vec3( 0.3));

}
