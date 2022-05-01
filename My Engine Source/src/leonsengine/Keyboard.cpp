#include "Keyboard.h"


namespace myengine
{
	void Keyboard::removeKey(int keyCode)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (keyCodes.at(i) == keyCode)
			{
				keyCodes.erase(keyCodes.begin() + i);
				i--;
			}


		}
	}
	bool Keyboard::getKey(int keyCode)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (keyCodes.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::getKeyDown(int keyCode)
	{
		return false;
	}

	bool Keyboard::getKeyUp(int keyCode)
	{
		return false;
	}
}
