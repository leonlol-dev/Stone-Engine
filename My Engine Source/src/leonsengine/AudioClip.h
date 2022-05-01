#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <string>
#include "Resource.h"



namespace myengine
{
	struct AudioSource;

	/// This is the Audioclip, this holds the audioclip (e.g ogg, mp3, etc) that is then played by a AudioSource. 
	///
	/// AudioClip has two functions: onInit(), which when the game initialises it will start to set up the necessary functions to work such as buffers. And loadOgg() loads the audio. Because AudioClip is a
	/// resource we can use getPath() to find the necessary path to that file.

	struct AudioClip : Resource
	{	
		/// OnInit(), when the core starts, this function will be called. 
		void onInit();

		/// LoadOgg loads the audio file by path.
		/// @param fileName This is the file location.
		/// @param buffer This is the buffer for the audio.
		/// @param format Describes if it's mono or stereo.
		/// @param freq Sample Rate.
		void loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

	private:

		friend struct AudioSource;
		ALenum format;
		ALsizei freq;
		ALuint id;
		std::vector<char> bufferData;

	};


}