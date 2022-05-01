#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>



namespace myengine
{
	struct Transform;
	struct Model;
	struct ShaderProgram;
	
	///This is the camera component, it's what the player will see.
	///
	///Add this into the scene and you can manipulate what the camera see by changing the camera entity's transform (translate, rotation and scale).
	///This is essentially an empty game object but we input the camera position and rotation into the shaders.
	struct Camera : Component
	{
		Camera();

		/// When the camera's onInit() is called it register itself to the core so it's transform can be accessed.
		void onInit();

		/// When the cameras destroyed, it needs to unregister itself in core.
		void onDestroy();

	private:
		friend struct myengine::Core;
		glm::mat4 view;
	};
}