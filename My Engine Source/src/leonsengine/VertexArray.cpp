#include "bugl.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include <exception>




namespace myengine
{

	VertexArray::VertexArray()
	{
		//Vertex Array Constructor

		glGenVertexArrays(1, &id);

		if (!id)
		{
			throw std::exception();

		}

		buffers.resize(20);
		dirty = true;
		vertCount = 0;
	}

	VertexArray::VertexArray(std::string path)
	{
		//Vertex Array Constructor for model files
		id = buLoadModel(path, &vertCount);
		dirty = false;
	}



	VertexArray::~VertexArray()
	{
		//Destructor for Vertex Array
		glDeleteVertexArrays(1, &id);
	}

	size_t VertexArray::getVertCount()
	{
		//Returns the vertex count
		return vertCount;
	}

	void VertexArray::setBuffer(int position, std::shared_ptr<VertexBuffer> buffer)
	{
		//Sets the buffer for the vertex array
		buffers.at(position) = buffer;
		dirty = true;

	}

	GLuint VertexArray::getId()
	{
		//Returns ID and binds the buffer
		if (dirty)
		{
			dirty = false;
			glBindVertexArray(id);

			for (size_t i = 0; i < buffers.size(); i++)
			{
				if (!buffers.at(i)) continue;

				// Bind the position VBO, assign it to position 0 on the bound VAO
				// and flag it to be used
				glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->getId());

				glVertexAttribPointer(i, buffers.at(i)->getComponents(), GL_FLOAT, GL_FALSE,
					0, (void*)0);

				glEnableVertexAttribArray(i);

			}

			glBindVertexArray(0);
		}

		return id;
	}

}