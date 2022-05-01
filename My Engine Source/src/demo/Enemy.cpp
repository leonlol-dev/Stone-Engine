#include "Enemy.h"


Enemy::Enemy(bool _spin)
{
	spin = _spin;
	hasEntered = false;
}
void Enemy::onInit()
{
	//std::shared_ptr<TriangleRenderer> triangle = getEntity()->addComponent<TriangleRenderer>();
	std::shared_ptr<SphereCollider> collider = getEntity()->addComponent<SphereCollider>();

	std::shared_ptr<Model> model = getCore()->getResources()->load<Model>("../Assets/curuthers/curuthers");
	
	
	std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>("../Assets/curuthers/Whiskers_diffuse.png");

	
	modelrend = getEntity()->addComponent<ModelRenderer>(model);
	modelrend->setTexture(tex);

	//Skeleton related stuff
	skeleton = getCore()->getResources()->load<Model>("../Assets/skeleton/Skeleton");
	skeletontex = getCore()->getResources()->load<Texture>("../Assets/skeleton/Skeleton_Texture.png");

	//Sound effect
	audio1 = getEntity()->addComponent<AudioSource>();
	s = getCore()->getResources()->load<AudioClip>("../Assets/scream");

}

void Enemy::onTick()
{
	if (spin)
	{
		getEntity()->getTransform()->rotate(glm::vec3(getCore()->getEnvironment()->getDeltaTime() * 100));
	}
}

void Enemy::onCollision(std::shared_ptr<SphereCollider> sc)
{
	if (!hasEntered)
	{
		hasEntered = true;
		modelrend->setTexture(skeletontex);
		modelrend->setModel(skeleton);
		audio1->setClip(s);
		//getEntity()->getTransform()->setPosition(glm::vec3(4.0f, -1.5f, -10.0f));
	}

}