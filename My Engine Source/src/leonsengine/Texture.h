#include "Resource.h"
#include "ShaderProgram.h"
#pragma once

namespace myengine
{
	struct ModelRenderer;

	///This is the Texture class, It stores images.
	///
	///OnInit() gets the path of the image using resource's getPath() function which the texture class inherits and the stb_image library. Then does OpenGL functions such as bindTexture, mip mapping, etc.
	struct Texture : Resource
	{
		///Gets the texture resource and loads it, uploads data to GPU and then frees it.
		void onInit();
		void loadTexture();

		///Returns Texture ID.
		GLuint getId();

		///Returns Texture size.
		glm::vec2 getSize();

	private:
		friend struct myengine::ModelRenderer;
		glm::vec2 size;
		int w = 0;
		int h = 0;
		int channels = 0;
		GLuint id;
	};



}