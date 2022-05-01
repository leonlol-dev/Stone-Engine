#pragma once

#include <vector>
#include <SDL.h>

namespace myengine
{
	struct Core;

	///The Keyboard class handles the keyboard within our game engine. It uses a vectors to see what keys are being pushed via the event system with SDL_Events.
	struct Keyboard
	{
		///Gets the key.
		///@param keyCode Keyboard input.
		bool getKey(int keyCode);

		///Returns true if key is down.
		///@param keyCode Keyboard input.
		bool getKeyDown(int keyCode);

		///Returns true if key is up.
		///@param keyCode Keyboard input.
		bool getKeyUp(int keyCode);

	private:
		friend struct myengine::Core;
		std::vector<int> keyCodes;
		void removeKey(int keyCode);
	};

}