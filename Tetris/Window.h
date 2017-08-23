#ifndef _WINDOW_H
#define _WINDOW_H
#include<string>
#include"Config.h"
#include"Texture.h"
#include"Shader.h"
#include"Font.h"
#include"Game.h"
class Window{
public:
	void Init();
	void Start();
	static GLboolean keepDown;
private:
	void loadResources();
	std::shared_ptr<Texture> loadTextureFromFile(const std::string& file, bool alpha);
	std::shared_ptr<Shader> loadShadersFromFile(const std::string& vertexFile, const std::string & fragmentFile, const std::string& geometryFile=std::string());
	void initWindow(GLuint screenWidth, GLuint screeHeight);
	//void keyCallBack(GLFWwindow*window, int key, int scancode, int action, int mode);
	void Do_MoveDown();
	std::shared_ptr<Texture> background1;
	std::shared_ptr<Texture> background2;
	std::shared_ptr<Texture> background3;
	GLFWwindow *window;
	std::shared_ptr<Texture> block;
	std::shared_ptr<Font> font;
	std::shared_ptr<Shader> squareShader;
	std::shared_ptr<Shader> textShader;
	GLuint width;
	GLuint height;
	Game game;
};
#endif