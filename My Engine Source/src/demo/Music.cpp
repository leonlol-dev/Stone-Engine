#include "Music.h"

void Music::onInit()
{
	std::shared_ptr<AudioSource> audio = getEntity()->addComponent<AudioSource>();
	std::shared_ptr<AudioClip> s = getCore()->getResources()->load<AudioClip>("../Assets/pizza");

	audio->setClip(s);


}