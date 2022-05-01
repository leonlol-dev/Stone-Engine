#pragma once

#include <string>
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
#include "Material.h"
#include "Texture.h"

namespace myengine
{

	struct VertexArray;
	struct ShaderProgram;
	struct Transform;
	struct Model;
	struct Material;

	///This is the model renderer. It renders a model.
	///
	///The model renderer has multiple variable needed to render which is the shader, vao, model, texture and optionally material. The user has to to set the model first as the model renderer
	///requires a model object in the constructor. onDisplay() function is what displays the model using the shader and setting the uniforms to the shaders as well as binding the wanted texture.
	///Users can change the shaders using material resource. 
	struct ModelRenderer : Component
	{
		ModelRenderer(std::shared_ptr<Model> _model);

		///Sets the model using a file path.
		///@param _path The file path.
		void setModel(std::string _path);

		///Sets the model using a shared_ptr.
		///@param _model the Model you want to set.
		void setModel(std::shared_ptr<Model> _model);

		///Sets the material.
		///@param _mat The material you want to set.
		void setMaterial(std::shared_ptr<Material> _mat);

		///Sets the texture.
		///@param _tex The texture you want to set.
		void setTexture(std::shared_ptr<Texture> _tex);

		///Just before the screen is cleared, onDisplay() is called.
		void onDisplay();
		
		///Just before core starts, onBegin() is called.
		void onBegin();

	private:
		friend struct myengine::Core;
		std::shared_ptr<ShaderProgram> shader;
		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<Model> model;
		std::shared_ptr<Texture> tex;
		std::shared_ptr<Material> mat;

	};


}