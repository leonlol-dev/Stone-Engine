#include "Resource.h"
#include "ShaderProgram.h"
#include <memory>
#pragma once
namespace myengine
{
	struct ModelRenderer;
	struct ShaderProgram;

	///This is similar to Unity's material system, it lets the user add a shader to a gameobject such as a model.

	struct Material : Resource
	{
		void onInit();

	private:
		friend struct myengine::ModelRenderer;
		std::shared_ptr<ShaderProgram> shader;
	};
}