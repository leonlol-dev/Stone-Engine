#include "Transform.h"
#include <glm/ext.hpp>

namespace myengine
{
	Transform::Transform()
	{

		scale = glm::vec3(1.0f, 1.0f, 1.0f);
		position = glm::vec3(0.0f, 0.0f, 0.0f);
		rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		
	}
	glm::mat4 Transform::getModel()
	{
		glm::mat4 rtn(1.0f);
		rtn = glm::translate(rtn, position);
		rtn = glm::rotate(rtn, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		rtn = glm::rotate(rtn, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		rtn = glm::rotate(rtn, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		rtn = glm::scale(rtn, scale);
		return rtn;
	}

	void Transform::setPosition(glm::vec3 _position)
	{
		position = _position;
	}

	void Transform::setRotation(glm::vec3 _rotation)
	{
		rotation = _rotation;
		
	}

	void Transform::setScale(glm::vec3 _scale)
	{
		scale = _scale;
	}

	void Transform::move(float _amount)
	{
		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(0, 0, 1, 1));
		position += fwd * _amount;
	}

	void Transform::move(glm::vec3 _amount)
	{
		glm::mat4 model(1.0f);
		model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		glm::vec3 fwd = glm::vec3(model * glm::vec4(_amount, 1));
		position += fwd;


	}

	void Transform::rotate(glm::vec3 _rotate)
	{
		rotation += _rotate;

	}

	glm::vec3 Transform::getPosition()
	{
		return position;
	}

	glm::vec3 Transform::getRotation()
	{
		return rotation;
	}

	glm::vec3 Transform::getScale()
	{
		return scale;
	}
	


}