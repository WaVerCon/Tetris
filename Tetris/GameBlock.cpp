#include"GameBlock.h"
GameBlock::GameBlock(std::shared_ptr<Texture> tex, int x, int y, BlockType type) :texture(tex), center_x(x), center_y(y), type(type){
	for (int i = 0; i < 4; ++i)
		blocks[i] = nullptr;
	SetupSubBlocks();
}
void GameBlock::SetupSubBlocks(){
	for (int i = 0; i < 4; ++i){
		if (blocks[i] != nullptr){
			delete blocks[i];
			blocks[i] = nullptr;
		}
		switch (type){
			case SQUARE_BLOCK:{
				blocks[0] = new Block(center_x - SQUARE_MEDIAN, center_y - SQUARE_MEDIAN, texture);
				blocks[1] = new Block(center_x, center_y - SQUARE_MEDIAN, texture);
				blocks[2] = new Block(center_x - SQUARE_MEDIAN, center_y , texture);
			}
		}
	}
}