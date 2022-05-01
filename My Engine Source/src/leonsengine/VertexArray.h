#pragma once

#include "GL/glew.h"
#include <vector>
#include <memory>
#include <string>





namespace myengine
{
	struct VertexBuffer;

	///This is the VertexArray class, it gets the vertex array of a model or easily creates Vertex Array Objects with the functions availiable.
	///
	///The class has two constructors, one for models and one for user created objects. The one for model uses the Bournemouth University bugl.h library to obtain the vao of a object.
	
	struct VertexArray
	{
	public:

		///Vertex Array constructor.
		VertexArray();

		///Vertex Array constructor that takes in a path to a file.
		///@param path The path the model is located.
		VertexArray(std::string path); //Constructor for bugl.h

		///Delete its data.
		~VertexArray();

		///Sets the buffer.
		///@param position The position of the buffer.
		///@param buffers The Vertex Buffer Object.
		void setBuffer(int position, std::shared_ptr<VertexBuffer> buffers);

		//Returns the vertex array id.
		GLuint getId();

		///Returns the vertex count.
		size_t getVertCount();

	private:
		GLuint id;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		bool dirty;
		size_t vertCount;
	};




}