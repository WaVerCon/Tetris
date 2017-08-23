#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include"Config.h"

class Shader
{
public:
	GLuint ID;
	Shader(){}
	Shader & Use();
	void Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
	void SetFloat(const GLchar *name, GLfloat value, GLboolean useShader = false);
	void SetInteger(const GLchar *name, GLint value, GLboolean useShader = false);
	void SetVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);
	void SetVector2f(const GLchar *name,const glm::vec2 &value, GLboolean useShader = false);
	void SetVector3f(const GLchar *name, GLfloat x, GLfloat y,GLfloat z, GLboolean useShader = false);
	void SetVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader = false); 
	void SetVector4f(const GLchar *name, GLfloat x, GLfloat y,GLfloat z,GLfloat w, GLboolean useShader = false);
	void SetVector4f(const GLchar *name,const glm::vec4 &value, GLboolean useShader = false);
	void SetMatrix4f(const GLchar *name,const glm::mat4 &value, GLboolean useShader = false);
private:
	void checkCompileErrors(GLuint shaderObject, std::string type);
};

#endif