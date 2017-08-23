#ifndef _CONFIG_H
#define _CONFIG_H
#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<SOIL.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<memory>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 800
#define DOWN_SPEED 40
#define GAME_AREA_X 350
#define GAME_AREA_Y 600
#define HINT_AREA_X 150
#define HINT_AREA_Y 100
#define GAME_AREA_POS_X 10
#define GAME_AREA_POS_Y 10
#define HINT_AREA_POS_X 380
#define HINT_AREA_POS_Y 550
#define SQUARE_MEDIAN 20
#define FONT_SIZE_HEIGHT 30
typedef enum BlockType{
	SQUARE_BLOCK, T_BLOCK, L_BLOCK, LINE_BLOCK, S_BLOCK, BACKWARDS_S_BLOCK
} BlockType;
typedef enum Direction{UP,DOWN,LEFT,RIGHT} Direction;
#endif