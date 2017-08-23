#ifndef _TEXT_RENDERER_H
#define _TEXT_RENDERER_H
#include"Config.h"
#include"Shader.h"
#include"Texture.h"
#include"Font.h"
class TextRenderer{
public:
	void RenderText( Font &font, std::string text, glm::vec2 &position, const GLfloat scale, const glm::vec3& color);
	TextRenderer(Shader&shader);
	~TextRenderer(){};
private:
	GLuint textVAO;
	GLuint textVBO;
	Shader shader;
	void init();
};

#endif