#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Music.h"

using namespace myengine;


int main()
{
	

	std::shared_ptr<Core> core = Core::initialize();

	///Player Entity 
	std::shared_ptr<Entity> entity = core->addEntity();
	std::shared_ptr<Component> component = entity->addComponent<Component>();
	entity->addComponent<Player>();
	entity->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -10.0f));

	///Enemy Entity
	std::shared_ptr<Entity> entity2 = core->addEntity();
	entity2->addComponent<Enemy>(false);
	entity2->getTransform()->setPosition(glm::vec3(8.0f, 0.0f, -10.0f));

	///Enemy Entity
	std::shared_ptr<Entity> entity3 = core->addEntity();
	entity3->addComponent<Enemy>(true);
	entity3->getTransform()->setPosition(glm::vec3(-10.0f, 0.0f, -10.0f));

	///Enemy Entity
	std::shared_ptr<Entity> entity4 = core->addEntity();
	entity4->addComponent<Enemy>(false);
	entity4->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -25.0f));

	///Floor 
	std::shared_ptr<Entity> floor = core->addEntity();
	std::shared_ptr<TriangleRenderer> triangle = floor->addComponent<TriangleRenderer>();
	floor->getTransform()->setScale(glm::vec3(50.0f, 75.0f, 20.0f));
	floor->getTransform()->setPosition(glm::vec3(0.0f, -3.0f, -15.0f));
	floor->getTransform()->setRotation(glm::vec3(90.0f, 0.0f, 0.0f));

	///Music Entity 
	std::shared_ptr<Entity> music = core->addEntity();
	music->addComponent<Music>();
	
	///Camera Entity
	std::shared_ptr<Entity> camera = core->addEntity();
	std::shared_ptr<Camera> cam = camera->addComponent<Camera>();
	camera->getTransform()->setPosition(glm::vec3(0.0f, 15.0f, 15.0f)); //xyz
	camera->getTransform()->setRotation(glm::vec3(-25.0f, 0.0f, 0.0f));
	
	



	core->start();

	return 0;
}