#ifndef _SPRITE_RENDERER_H
#define _SPRITE_RENDERER_H
#include"Config.h"
#include"Shader.h"
#include"Texture.h"
class SpriteRenderer{
public:
	void Draw(const Texture& texture, const glm::vec2 &position, GLfloat rotate=0.0f, const glm::vec2 &scale=glm::vec2(1,1),const glm::vec3& color=glm::vec3(1.0f));
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();
private:
	GLuint VAO;
	Shader shader;
	void init();
};

#endif