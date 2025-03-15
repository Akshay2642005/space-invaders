#pragma once
#include "laser.hpp"
#include <raylib.h>
#include <vector>

using namespace std;

class Spaceship {
public:
  Spaceship();
  ~Spaceship();
  void Draw();
  void MoveLeft();
  void MoveRight();
  void FireLaser();
  vector<Laser> lasers;

private:
  Texture2D img;
  Vector2 pos;
  double lastfiretime;
};
