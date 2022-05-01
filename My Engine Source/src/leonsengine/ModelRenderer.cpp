#include "ModelRenderer.h"
#include "Core.h"
#include "Keyboard.h"
#include "Entity.h"
#include "Transform.h"
#include "Model.h"
#include "Resources.h"
#include "Screen.h"
#include "Camera.h"

namespace myengine
{
	ModelRenderer::ModelRenderer(std::shared_ptr<Model> _model)
	{
		
		model = _model;
		shader = std::make_shared<ShaderProgram>("../Assets/shaders/vertexShader.txt", "../Assets/shaders/fragShader.txt");

	}


	void ModelRenderer::onDisplay()
	{
		///Use Shader Program and Bind Vertex Array
		glUseProgram(shader->getId());
		glBindVertexArray(model->vao->getId());
		
		///Set Shader Uniform Location
		shader->setMat4("u_Model", getEntity()->getTransform()->getModel());
		shader->setMat4("u_View", glm::inverse(getCore()->getCamera()->getEntity()->getTransform()->getModel()));
		shader->setMat4("u_Projection", glm::perspective(glm::radians(45.0f),
			(float)getCore()->getScreen()->getWidth() / (float)getCore()->getScreen()->getHeight(), 0.1f, 100.0f));
		shader->setInt("u_Texture", 0);
	

		///Bind the desired texture
		glBindTexture(GL_TEXTURE_2D, tex->getId());

		// Draw 3 vertices (a triangle)
		glDrawArrays(GL_TRIANGLES, 0, model->vao->getVertCount());

		// Reset the statea
		glBindVertexArray(0);
		glUseProgram(0);


	}

	void ModelRenderer::setModel(std::string path)
	{
		getCore()->getResources()->load<Model>(path + ".obj");
	
	}

	void ModelRenderer::setModel(std::shared_ptr<Model> _model)
	{
		model = _model;

	}

	void ModelRenderer::setMaterial(std::shared_ptr<Material> _mat)
	{
		shader = _mat->shader;
	}

	void ModelRenderer::setTexture(std::shared_ptr<Texture> _tex)
	{
		tex = _tex;
	}

	void ModelRenderer::onBegin()
	{

	}


}