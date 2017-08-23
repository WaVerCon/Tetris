#include"Font.h"
void Font::Init(){
	loadCharacters();
}
void Font::loadCharacters(){
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Cound not init FreeType Library" << std::endl;
	FT_Face face;
	if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
		std::cout << "ERROR:FREETYPE: Faild to load font" << std::endl;
	FT_Set_Pixel_Sizes(face, 0, FONT_SIZE_HEIGHT);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (GLchar c = 0; c < 128; ++c){
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)){
			std::cout << "ERROR::FREETYPE:: Failed to load Glyph" << std::endl;
			continue;
		}
		Texture texture;
		texture.Internal_format = GL_RED;
		texture.Image_format = GL_RED;
		texture.Wrap_S = GL_CLAMP_TO_EDGE;
		texture.Wrap_T = GL_CLAMP_TO_EDGE;
		texture.Generate(face->glyph->bitmap.width, face->glyph->bitmap.rows, face->glyph->bitmap.buffer);
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::make_pair(c, character));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}