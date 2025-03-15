#include "headers/spaceship.hpp"

Spaceship::Spaceship() {
  img = LoadTexture("graphics/spaceship.png");
  pos.x = (float)(GetScreenWidth() - img.width) / 2;
  pos.y = (GetScreenHeight() - img.height - 20);
  lastfiretime = 0.0;
}
Spaceship::~Spaceship() { UnloadTexture(img); }

void Spaceship::Draw() { DrawTexture(img, pos.x, pos.y, WHITE); }

void Spaceship::MoveLeft() {
  pos.x -= 7;
  if (pos.x < 0) {
    pos.x = 0;
  }
}

void Spaceship::MoveRight() {
  pos.x += 7;
  if (pos.x > GetScreenWidth() - img.width - 25) {
    pos.x = GetScreenWidth() - img.width - 25;
  }
}

void Spaceship::FireLaser() {
  if (GetTime() - lastfiretime > 0.35) {
    lasers.push_back(Laser({pos.x + (float)img.width / 2 - 2, pos.y}, -6));
    lastfiretime = GetTime();
  }
}
