#include "headers/block.hpp"

Block::Block(Vector2 pos) { this->pos = pos; }

void Block::Draw() { DrawRectangle(pos.x, pos.y, 3, 3, {243, 216, 63, 255}); }
