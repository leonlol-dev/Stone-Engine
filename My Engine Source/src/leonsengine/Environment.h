#pragma once

#include <SDL.h>
namespace myengine
{
	///This is the environment, this is mainly for physics based functionalities such as delta times.
	///@note Adding physics will be a wanted feature for my game engine. 
	struct Environment
	{
		///Returns delta time.
		float getDeltaTime();
		
		///Calculates the delta time.
		float calculateDeltaTme();

		///Gets the last tick of our engine. Used for calculating delta time.
		Environment();

	private:
		float time;
		float diff;
		float deltaTime;
		float lastTime;
	};

}