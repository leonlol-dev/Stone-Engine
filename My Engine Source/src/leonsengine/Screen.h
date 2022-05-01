#pragma once

#include "SDL.h"

namespace myengine
{
	///This is the screen class, it just stores the height and width variables and has functions to give the values to other objects.
	struct Screen
	{
	public:

		///Returns the width of the screen.
		int getWidth();

		///Returns the height of the screen.
		int getHeight();

	private:
		int height = 600;
		int width = 800;
		
	};

}