#include "headers/alien.hpp"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 pos) {
  this->type = type;
  this->pos = pos;

  if (alienImages[type - 1].id == 0) {
    switch (type) {
    case 1:
      alienImages[0] = LoadTexture("graphics/alien_1.png");
      break;
    case 2:
      alienImages[1] = LoadTexture("graphics/alien_2.png");
      break;
    case 3:
      alienImages[2] = LoadTexture("graphics/alien_3.png");
      break;
    default:
      alienImages[0] = LoadTexture("graphics/alien_1.png");
      break;
    }
  }
}

void Alien::Draw() { DrawTextureV(alienImages[type - 1], pos, WHITE); }

int Alien::GetType() { return type; }

void Alien::UnloadImages() {
  for (int i = 0; i < 4; i++) {
    UnloadTexture(alienImages[i]);
  }
}

void Alien::Update(int direction) { pos.x += direction; }
