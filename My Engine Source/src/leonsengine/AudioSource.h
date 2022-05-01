#pragma once

#include "Component.h"
#include <AL/al.h>
#include <AL/alc.h>
#include "AudioClip.h"


namespace myengine
{
	/// This is the AudioSource, this plays the audioclip (e.g ogg, mp3, etc). 
	/// 
	/// AudioSource has a function that sets the clip which takes in a audioclip. To play we use the OpenAL library, as show by the setClip() function. 
	///
	

	struct AudioSource : Component
	{
		AudioSource();

		/// This function sets the audio clip to be played.
		/// @param clip The audio clip that the you want to play.
		void setClip(std::shared_ptr<AudioClip> clip);

	private:
		ALuint sid;

		float volume;
		float variance;
	};

}