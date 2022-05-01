#include "Material.h"

namespace myengine
{
	void Material::onInit()
	{
		shader = std::make_shared<ShaderProgram>(getPath(), getPath());
	}
}