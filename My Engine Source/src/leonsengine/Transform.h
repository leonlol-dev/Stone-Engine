#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace myengine
{
	///This is the transform class, it allows the user to move around game objects and set initial the position, rotation and/or scale.
	///@param _position The position you want to set.
	///@param _rotation The rotation you want to set.
	///@param _scale The scale you want to set.
	///@param _amount The amount you want to move/rotate. 

	struct Transform : Component
	{
		Transform();

		///Returns the transform's model.
		glm::mat4 getModel();

		///Sets the position of the entity.
		///@param _position The desired position you want to set.
		void setPosition(glm::vec3 _position);

		///Sets the rotation of an entity.
		///@param _rotation The desired rotation you want to set.
		void setRotation(glm::vec3 _rotation);

		///Sets the scale of an entity.
		///@param _scale The desired scale you want to set.
		void setScale(glm::vec3 _scale);

		///Player Movement in our tech demo
		///@param _amount is the amount you want to move
		void move(float _amount);

		///Player Movement in our tech demo
		///@param _amount is the amount you want to move
		void move(glm::vec3 _amount);

		///Spins/rotates the entity.
		///@param _amount The amount you want to rotate.
		void rotate(glm::vec3 _amount);

		///Returns rotation.
		glm::vec3 getRotation();

		///Returns scale.
		glm::vec3 getScale();

		///Returns position.
		glm::vec3 getPosition();

	private:
		friend struct myengine::Entity;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
	};
}