#include "headers/game.hpp"
#include <raylib.h>
const Color grey = {29, 29, 27, 255};

void gameWindow() {
  Game game;
  while (!WindowShouldClose()) {
    game.HandelInput();
    game.Update();
    BeginDrawing();
    ClearBackground(grey);
    game.Draw();
    EndDrawing();
  }
}

int main() {
  int windowWidth = 750;
  int windowHeight = 700;
  InitWindow(windowWidth, windowHeight, "Space-Wars");
  SetTargetFPS(60);
  gameWindow();
  CloseWindow();
}
