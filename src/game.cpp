#include "headers/game.hpp"
#include "headers/obstacle.hpp"
#include <raylib.h>

using namespace std;

Game::Game() {
  obstacles = createObstacles();
  aliens = createAliens();
  alienDirection = 1;
}
Game::~Game() { Alien::UnloadImages(); }

void Game::Update() {
  for (auto &laser : ship.lasers) {
    laser.Update();
  }

  MoveAliens();
  AlienLaser();

  for (auto &laser : alienLasers) {
    laser.Update();
  }

  deleteInactiveLasers();
}

void Game::Draw() {
  ship.Draw();
  for (auto &laser : ship.lasers) {
    laser.Draw();
  }
  for (auto &obstacle : obstacles) {
    obstacle.Draw();
  }
  for (auto &alien : aliens) {
    alien.Draw();
  }
  for (auto &laser : alienLasers) {
    laser.Draw();
  }
}

void Game::HandelInput() {
  if (IsKeyDown(KEY_LEFT)) {
    ship.MoveLeft();
  } else if (IsKeyDown(KEY_RIGHT)) {
    ship.MoveRight();
  } else if (IsKeyPressed(KEY_SPACE)) {
    ship.FireLaser();
  }
}

void Game::deleteInactiveLasers() {
  for (auto it = ship.lasers.begin(); it != ship.lasers.end();) {
    if (!it->active) {
      it = ship.lasers.erase(it);
    } else {
      ++it;
    }
  }
}

vector<Obstacle> Game::createObstacles() {
  int obstacleWidth = Obstacle::grid[0].size() * 3;
  float gap = (float)(GetScreenWidth() - (4 * obstacleWidth)) / 5;
  for (int i = 0; i < 4; i++) {
    float offsetX = (i + 1) * gap + i * obstacleWidth;
    obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 120)}));
  }
  return obstacles;
}

vector<Alien> Game::createAliens() {
  vector<Alien> aliens;
  for (int row = 0; row < 5; row++) {
    for (int column = 0; column < 11; column++) {
      int type;
      if (row == 0) {
        type = 3;
      } else if (row == 1 || row == 2) {
        type = 2;
      } else {
        type = 1;
      }
      float x = 75 + column * 55;
      float y = 110 + row * 55;
      aliens.push_back(Alien(type, {x, y}));
    }
  }
  return aliens;
}

void Game::MoveAliens() {
  for (auto &alien : aliens) {
    if (alien.pos.x + alien.alienImages[alien.type - 1].width >
        GetScreenWidth()) {
      alienDirection = -1;
      MoveAliensDown(4);
    }
    if (alien.pos.x < 0) {
      alienDirection = 1;
      MoveAliensDown(4);
    }
    alien.Update(alienDirection);
  }
}

void Game::MoveAliensDown(int distance) {
  for (auto &alien : aliens) {
    alien.pos.y += distance;
  }
}

void Game::AlienLaser() {
  int randomIndex = GetRandomValue(0, aliens.size() - 1);
  Alien &alien = aliens[randomIndex];
  alienLasers.push_back(
      Laser({(alien.pos.x + (float)alien.alienImages[alien.type - 1].width / 2),
             alien.pos.y + alien.alienImages[alien.type - 1].height},
            6));
}
