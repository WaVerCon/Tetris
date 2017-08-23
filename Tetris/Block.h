#ifndef _BLOCK_H
#define _BLOCK_H
#include"Texture.h"
#include"SpriteRenderer.h"
#include"Config.h"
class Block{
public:
	void Draw(SpriteRenderer *renderer);
	void Move(Direction dir);
	void SetX(int x){
		center_x = x;
	}
	int GetX(){
		return center_x;
	}
	void SetY(int y){
		center_y = y;
	}
	int GetY(){
		return center_y;
	}
	Block(int x,int y,std::shared_ptr<Texture> texture):center_x(x),center_y(y),texture(texture){}
private:
	int center_x;
	int center_y;
	std::shared_ptr<Texture> texture;
	
};
#endif