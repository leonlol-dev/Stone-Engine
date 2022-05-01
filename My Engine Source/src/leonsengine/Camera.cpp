#include "Camera.h"
#include "ShaderProgram.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Model.h"

namespace myengine
{
	Camera::Camera()
	{
		//core set camera
		view = glm::mat4(1.0f);
		

	}

	void Camera::onInit()
	{
		getCore()->registerCamera(getEntity()->getComponent<Camera>());
	}

	void Camera::onDestroy()
	{
		getCore()->unregisterCamera(this);
	}

}