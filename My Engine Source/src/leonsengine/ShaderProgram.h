#pragma once

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp> 
#include <string>
#include "VertexArray.h"

namespace myengine
{
	/// This is the shader program. It handles anything to do with the vertex shader and fragment shader of OpenGL.
	///
	/// The constructor of the shader program takes in the path of the vertex and fragment shader files, converts it into string and then attaches it into OpenGL.
	/// The shader program is also responsible for sending the uniform locations and functions to the shader via the void functions - this is done usually in the the model renderer. 
	struct ShaderProgram
	{
	public:

		///On the constructor, the shader program takes in a vertex shader path and fragment shader path. 
		///@param vertexPath The vertex shader file path.
		///@param fragmentPath The fragment shader file path.
		ShaderProgram(std::string vertexPath, std::string fragmentPath);

		///Deletes the shader.
		~ShaderProgram();
		GLuint getId();

		//Utility Uniform Functions

		///Sets bool uniform location.
		void setBool(const std::string& name, bool value) const;

		///Sets int uniform location.
		///@note Used for Sampler2D textures.
		void setInt(const std::string& name, int value) const;

		///Sets float uniform location.
		void setFloat(const std::string& name, float value) const;

		///Sets vec2 uniform location.
		void setVec2(const std::string& name, const glm::vec2& value) const;

		///Sets vec2 uniform location.
		void setVec2(const std::string& name, float x, float y) const;

		///Sets vec3 uniform location.
		void setVec3(const std::string& name, const glm::vec3& value) const;

		///Sets vec3 uniform location.
		void setVec3(const std::string& name, float x, float y, float z) const;

		///Sets vec4 uniform location.
		void setVec4(const std::string& name, const glm::vec4& value) const;

		///Sets vec4 uniform location.
		void setVec4(const std::string& name, float x, float y, float z, float w);

		///Sets mat2 uniform location.
		void setMat2(const std::string& name, const glm::mat2& mat) const;

		///Sets mat3 uniform location.
		void setMat3(const std::string& name, const glm::mat3& mat) const;

		///Sets mat4 uniform location.
		///@note Used for Model, Projection and View.
		void setMat4(const std::string& name, const glm::mat4& mat) const;

		


	private:
		GLuint id;
		GLuint fragmentShaderId;
		GLuint vertexShaderId;
		void errorCheck(GLuint shader, std::string type);
		bool CheckShaderCompiled(GLuint shader);





	};

}