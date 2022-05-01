#pragma once

#include "GL/glew.h"
#include <glm/glm.hpp>
#include <vector>
#include <memory>


namespace myengine
{
	///This is Vertex Buffer class that builds Vertex Buffer Objects.
	///
	///The VBO is created by adding a vector of 3 or 4 to the object and then this is sent off the the Vertex Array Object.
	///@param value The vector of what you want to add to the VBO.

	struct VertexBuffer
	{
	public:

		///Constructor that initialises anything that the vertex buffer requires.
		VertexBuffer();

		///Destructor that deletes the data.
		~VertexBuffer();

		///Adds data into our Vertex Buffer Object
		///@param value Vector3 data.
		void add(glm::vec3 value);

		///Adds data into our Vertex Buffer Object
		///@param value Vector4 data.
		void add(glm::vec4 value);

		///Returns the ID.
		GLuint getId();

		///Gets the components.
		int getComponents();

	private:
		GLuint id;
		std::vector<GLfloat> data;
		bool dirty;
		int components;

	};




}