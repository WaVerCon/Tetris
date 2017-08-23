#ifndef _GAME_BLOCK_H
#define _GAME_BLOCK_H
#include"Block.h"
#include<memory>
class GameBlock{
public:
	void Rotate();
	GameBlock(std::shared_ptr<Texture> texture, int x, int y, BlockType type);
	~GameBlock();
	
	std::unique_ptr<int[]> GetRotatedPosition();
	void Move(Direction dir);
	void Draw(SpriteRenderer *renderer);
	int GetX(){ return center_x; }
	int GetY(){ return center_y; }
	void SetX(int x){ center_x = x; }
	void SetY(int y){ center_y = y; }
private:
	int center_x;
	int center_y;
	std::shared_ptr<Texture> texture;
	Block* blocks[4];
	BlockType type;
	void SetupSubBlocks();
};
#endif