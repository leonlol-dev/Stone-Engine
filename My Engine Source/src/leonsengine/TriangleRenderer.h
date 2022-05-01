#pragma once

#include "GL/glew.h"
#include "SDL.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp> 
#include <exception>
#include <iostream>
#include <memory>
#include "Component.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

namespace myengine
{
	struct VertexArray;
	struct ShaderProgram;
	struct Transform;

	///This is the triangle renderer, this renders a triangle - this is mainly for debugging purposes.

	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void onTick();
		void onDisplay();
		void onBegin();

	private:
		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<VertexArray> cat;
	};

	




}