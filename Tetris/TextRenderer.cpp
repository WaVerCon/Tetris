#include"TextRenderer.h"
void TextRenderer::RenderText( Font &font, std::string text, glm::vec2& position, GLfloat scale, const glm::vec3& color){
	shader.Use();
	shader.SetVector3f("textColor", color);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(textVAO);
	std::map<GLchar, Font::Character> &Characters = font.getCharacters();
	for (int i = 0; i < text.length(); ++i){
		Font::Character ch = Characters[text[i]];
		GLfloat xpos = position.x + ch.Bearing.x*scale;
		GLfloat ypos = position.y - (ch.Size.y - ch.Bearing.y)*scale;
		GLfloat w = ch.Size.x*scale;
		GLfloat h = ch.Size.y*scale;
		GLfloat vertices[6][4] = {
			{ xpos, ypos + h, 0.0, 0.0 },
			{ xpos, ypos, 0.0, 1.0 },
			{ xpos + w, ypos, 1.0, 1.0 },
			{ xpos, ypos + h, 0.0, 0.0 },
			{ xpos + w, ypos, 1.0, 1.0 },
			{ xpos + w, ypos + h, 1.0, 0.0 }
		};
		glBindTexture(GL_TEXTURE_2D, ch.Texture.ID);
		glBindBuffer(GL_ARRAY_BUFFER, textVBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		position.x += (ch.Advance >> 6)*scale;

	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
TextRenderer::TextRenderer(Shader &shader) :shader(shader){
	init();
}
void TextRenderer::init(){
	//initialize text vao
	glGenVertexArrays(1, &textVAO);
	glGenBuffers(1, &textVBO);
	glBindBuffer(GL_ARRAY_BUFFER, textVBO);
	glBufferData(GL_ARRAY_BUFFER, 6 * 4 * sizeof(GLfloat), NULL, GL_DYNAMIC_DRAW);
	glBindVertexArray(textVAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}