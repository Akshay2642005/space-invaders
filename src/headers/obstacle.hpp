#pragma once
#include "block.hpp"
#include <vector>

using namespace std;

class Obstacle {
public:
  Obstacle(Vector2 pos);
  void Draw();
  Vector2 pos;
  vector<Block> blocks;
  static vector<vector<int>> grid;

private:
};
