#pragma once
#include "alien.hpp"
#include "laser.hpp"
#include "obstacle.hpp"
#include "spaceship.hpp"

using namespace std;

class Game {
public:
  Game();
  ~Game();
  void Draw();
  void Update();
  void HandelInput();

private:
  void deleteInactiveLasers();
  vector<Obstacle> createObstacles();
  vector<Alien> createAliens();
  void MoveAliens();
  void MoveAliensDown(int distance);
  void AlienLaser();
  Spaceship ship;
  vector<Obstacle> obstacles;
  vector<Alien> aliens;
  int alienDirection;
  vector<Laser> alienLasers;
};
