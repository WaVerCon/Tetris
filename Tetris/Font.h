#ifndef _FONT_H
#define _FONT_H
#include"Config.h"
#include"Texture.h"
#include<map>
#include<ft2build.h>
#include<iostream>
#include FT_FREETYPE_H
class Font{
public:
	struct Character{
		Texture Texture;
		glm::ivec2 Size;
		glm::ivec2 Bearing;
		GLuint Advance;
	};
	void Init();
	std::map<GLchar, Character>& getCharacters(){ return Characters; }
private:
	void loadCharacters();
	std::map<GLchar, Character> Characters;
};
#endif