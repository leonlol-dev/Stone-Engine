#include "Model.h"
#include "VertexArray.h"

namespace myengine
{

	void Model::onInit()
	{
		vao = std::make_shared<VertexArray>(getPath() + ".obj");
	}
}