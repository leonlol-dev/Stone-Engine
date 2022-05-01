#include "TriangleRenderer.h"
#include "Core.h"
#include "Keyboard.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"

namespace myengine
{
	TriangleRenderer::TriangleRenderer()
	{

		//Create Position Buffer
		std::shared_ptr<VertexBuffer> positionsVbo = std::make_shared<VertexBuffer>();
		positionsVbo->add(glm::vec3(0.0f, 0.5f, 0.0f));
		positionsVbo->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positionsVbo->add(glm::vec3(0.5f, -0.5f, 0.0f));

		//Create Colour Buffer
		std::shared_ptr<VertexBuffer> colorVbo = std::make_shared<VertexBuffer>();
		colorVbo->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		colorVbo->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		colorVbo->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		//Create Vertex Array
		vao = std::make_shared<VertexArray>();
		vao->setBuffer(0, positionsVbo);
		vao->setBuffer(1, colorVbo);

		//Shader Program
		shader = std::make_shared<ShaderProgram>("../Assets/shaders/vertexShader.txt", "../Assets/shaders/whiteFragShader.txt");

	}

	void TriangleRenderer::onTick()
	{

	}

	void TriangleRenderer::onDisplay()
	{
		// Instruct OpenGL to use our shader program and our VAO
		//Shader class -> get id in here.
		glUseProgram(shader->getId());
		glBindVertexArray(vao->getId());

		shader->setMat4("u_Model", getEntity()->getTransform()->getModel());
		shader->setMat4("u_Projection", glm::perspective(glm::radians(45.0f),
			800.0f / 600.0f, 0.1f, 100.0f));
		shader->setMat4("u_View", glm::inverse(getCore()->getCamera()->getEntity()->getTransform()->getModel()));

		// Draw 3 vertices (a triangle)
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Reset the statea
		glBindVertexArray(0);
		glUseProgram(0);

	}

	void TriangleRenderer::onBegin()
	{
		//Set position of triangle/mesh by default
		//getEntity()->getTransform()->setPosition(glm::vec3(5.0f, 0.5f, -3.0f));
	}


}
