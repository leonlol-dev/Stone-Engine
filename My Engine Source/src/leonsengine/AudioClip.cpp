
#include "AudioClip.h"
#include "stb_vorbis.h"
#include "Exception.h"

namespace myengine
{
	void AudioClip::onInit()
	{
		format = 0;
		freq = 0;

		alGenBuffers(1, &id);

		// load ogg here
		loadOgg(getPath() + ".ogg", bufferData, format, freq);

		alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);

	}
	void AudioClip::loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw Exception("Failed to open file '" + fileName + "' for decoding");
		}

		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}

		else
		{
			format = AL_FORMAT_STEREO16;
		}

		//Record the sample rate required by OpenAL
		freq = sampleRate;

		buffer.resize(samples * 2);
		memcpy(&buffer.at(0), output, buffer.size());

		//Clean up the read data
		free(output);
	}
}