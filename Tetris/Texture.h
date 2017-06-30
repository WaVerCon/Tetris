#ifndef _TEXTURE_H
#define _TEXTURE_H



class Texture
{
public:
	GLuint ID;
	GLuint Wrap_S;
	GLuint Wrap_T;
	GLuint Filter_min;
	GLuint Filter_max;
	GLuint Width;
	GLuint Height;
	GLuint Internal_format;
	GLuint Image_format;
	Texture();
	void Generate(GLuint width, GLuint height, unsigned char* data);
	void Bind() const;
};

#endif