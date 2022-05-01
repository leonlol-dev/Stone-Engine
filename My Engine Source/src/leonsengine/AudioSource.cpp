#include "AudioSource.h"


namespace myengine
{
	AudioSource::AudioSource()
	{
	
	}

	void AudioSource::setClip(std::shared_ptr<AudioClip> clip)
	{
		sid = 0;
		alGenSources(1, &sid);

		alSourcei(sid, AL_BUFFER, clip->id);
		alSourcePlay(sid);
	}


}