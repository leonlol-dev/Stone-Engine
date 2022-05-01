#pragma once
#include "Resource.h"

namespace myengine
{

	struct VertexArray;
	struct ModelRenderer;

	/// This is the model class. It stores the model that the user wants to use.
	///
	/// This class utilises the resources system within the game engine. It stores the vao of the .obj model. 
	struct Model : Resource
	{
		void onInit();

	private:
		friend struct myengine::ModelRenderer;
		std::shared_ptr<VertexArray> vao;
	};

}