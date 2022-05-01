#include "Environment.h"

namespace myengine
{
	float Environment::getDeltaTime()
	{
		return deltaTime;
	}

	float Environment::calculateDeltaTme()
	{
		time = SDL_GetTicks();
		diff = time - lastTime;
		deltaTime = diff / 1000.f;
		lastTime = time;
		return deltaTime;
	}

	Environment::Environment()
	{
		lastTime = SDL_GetTicks();
		deltaTime = 0.0f;

	}


}