#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Texture.h"
#include "Exception.h"

namespace myengine
{

	void Texture::onInit()
	{
		//On Init for the texture class.

		unsigned char* texture = stbi_load(getPath().c_str(), &w, &h, &channels, 4);
		if (!texture)
		{
			throw Exception("Failed to open file '" + getPath() + "' texture");
		}

		id = 0;
		glGenTextures(1, &id);
		if (!id)
		{
			throw Exception("No texture ID");
		}

		// Bind the Texture
		glBindTexture(GL_TEXTURE_2D, id);

		/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);*/

		// Upload image data to bound texture unit in the GPU.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture);

		// Free the loaded data because it has a copy within the GPU.
		free(texture);

		// Mipmap so texture can be mapped properly.
		glGenerateMipmap(GL_TEXTURE_2D);


	}

	GLuint Texture::getId()
	{
		return id;
	}

	glm::vec2 Texture::getSize()
	{
		return size;
	}




}