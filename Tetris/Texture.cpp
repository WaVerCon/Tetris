#include"Texture.h"
Texture::Texture():Width(0),Height(0),Internal_format(GL_RGB),Image_format(GL_RGB),Wrap_S(GL_REPEAT),Wrap_T(GL_REPEAT),Filter_min(GL_LINEAR),Filter_max(GL_LINEAR){
	glGenTextures(1, &this->ID);
}
void Texture::Generate(GLuint width, GLuint height, unsigned char *data){
	this->Width = width;
	this->Height = height;
	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, Internal_format, width, height, 0, Image_format, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_max);

	glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::Bind() const{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}