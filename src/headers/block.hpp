#pragma once
#include <raylib.h>

class Block {
public:
  Block(Vector2 pos);
  void Draw();

private:
  Vector2 pos;
};
