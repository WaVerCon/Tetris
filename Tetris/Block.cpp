#include"Block.h"
void Block::Draw(SpriteRenderer *renderer){
	renderer->Draw(*texture, glm::vec2(center_x - SQUARE_MEDIAN, center_y - SQUARE_MEDIAN), 0.0f,glm::vec2(SQUARE_MEDIAN*2));
}
void Block::Move(Direction dir){
	switch (dir){
	case DOWN:
		center_y -= DOWN_SPEED; break;
	case LEFT:
		center_x -= DOWN_SPEED; break;
	case RIGHT:
		center_x += DOWN_SPEED; break;
	default:break;
	}
}