#include"Window.h"
GLboolean Window::keepDown = GL_FALSE;
void keyCallBack(GLFWwindow*window, int key, int scancode, int action, int mode){
	if (key == GLFW_KEY_ESCAPE&&action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (action == GLFW_PRESS){
		switch (key){
			case GLFW_KEY_UP:{
				break;
			}
			case GLFW_KEY_LEFT:{
				break;
			}
			case GLFW_KEY_RIGHT:{
				break;
			}
			case GLFW_KEY_DOWN:{
				Window::keepDown = GL_TRUE;
				break;
			}
		}
	}
	if (action == GLFW_RELEASE&&key == GLFW_KEY_DOWN)
		Window::keepDown = GL_FALSE;
}
void Window::Do_MoveDown(){
	if (keepDown){
		
	}
}
void Window::initWindow(GLuint screenWidth,GLuint screenHeight){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwSetKeyCallback(window,keyCallBack);
	window = glfwCreateWindow(screenWidth, screenHeight, "Tetris", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0,0,screenWidth, screenHeight);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	width = screenWidth;
	height = screenHeight;
}
void Window::loadResources(){
	textShader = loadShadersFromFile("shaders/text.vert", "shaders/text.frag");
	squareShader = loadShadersFromFile("shaders/square.vert", "shaders/square.frag");
	background1 = loadTextureFromFile("textures/background1.png",GL_FALSE);
	background2 = loadTextureFromFile("textures/background2.png", GL_FALSE);
	background3 = loadTextureFromFile("textures/background3.png", GL_FALSE);
	block = loadTextureFromFile("textures/block.png", GL_FALSE);
	font = std::make_shared<Font>();
	font->Init();
}
std::shared_ptr<Shader> Window::loadShadersFromFile(const std::string& vertexFile, const std::string & fragmentFile, const std::string& geometryFile){
	std::shared_ptr<Shader> shader(new Shader());
	if (geometryFile != "")
		shader->Compile(vertexFile.c_str(), fragmentFile.c_str(), geometryFile.c_str());
	else
		shader->Compile(vertexFile.c_str(), fragmentFile.c_str());
	shader->Use();
	glm::mat4 projection = glm::ortho(0.0f, (GLfloat)width, 0.0f, (GLfloat)height);
	shader->SetMatrix4f("projection", projection);
	return shader;
}
std::shared_ptr<Texture> Window::loadTextureFromFile(const std::string& file, bool alpha){
	std::shared_ptr<Texture> texture(new Texture());
	int w, h;
	GLubyte* image = SOIL_load_image(file.c_str(), &w, &h, 0, alpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
	if (alpha){
		texture->Internal_format = GL_RGBA;
		texture->Image_format = GL_RGBA;
	}
	texture->Generate(w, h, image);
	SOIL_free_image_data(image);
	return texture;
}
void Window::Init(){
	initWindow(WINDOW_WIDTH,WINDOW_HEIGHT);
	loadResources();
	
}
void Window::Start(){
	GLfloat deltaTime = 0, lastFrame = 0;
	
	while (!glfwWindowShouldClose(window)){
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();
		Do_MoveDown();

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
	}
}