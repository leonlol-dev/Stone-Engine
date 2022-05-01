#include "Player.h"

void Player::onInit()
{
	std::shared_ptr<TriangleRenderer> triangle = getEntity()->addComponent<TriangleRenderer>();
	

	std::shared_ptr<SphereCollider> collider = getEntity()->addComponent<SphereCollider>();
	std::shared_ptr<Trigger> trigger = getEntity()->addComponent<Trigger>();
	std::shared_ptr<Model> model = getCore()->getResources()->load<Model>("../Assets/curuthers/curuthers");
	std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>("../Assets/curuthers/Whiskers_diffuse.png");


	std::shared_ptr<ModelRenderer> modelrend = getEntity()->addComponent<ModelRenderer>(model);
	modelrend->setTexture(tex);



}

void Player::onTick()
{//move the on tick to player as renderer isnt supposed to be here
	if (getCore()->getKeyboard()->getKey(SDLK_w) )
	{
		getEntity()->getTransform()->move(glm::vec3(0.0f, 0.0f, 25.0f) * getCore()->getEnvironment()->getDeltaTime() );

	}

	if (getCore()->getKeyboard()->getKey(SDLK_s))
	{
		getEntity()->getTransform()->move(glm::vec3(0.0f, 0.0f, -25.0f) * getCore()->getEnvironment()->getDeltaTime() );
	}

	if (getCore()->getKeyboard()->getKey(SDLK_d))
	{
		getEntity()->getTransform()->rotate(glm::vec3(0.0f, 80.0f, 0.0f) * getCore()->getEnvironment()->getDeltaTime() );

	}

	if (getCore()->getKeyboard()->getKey(SDLK_a))
	{
		getEntity()->getTransform()->rotate(glm::vec3(0.0f, -80.0f, 0.0f) * getCore()->getEnvironment()->getDeltaTime() );

	}
}


void Player::onCollision(std::shared_ptr<SphereCollider> sc)
{
	std::cout << "trigger" << std::endl;
}

	

