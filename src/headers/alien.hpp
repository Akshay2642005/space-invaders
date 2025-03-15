#include <raylib.h>

class Alien {
public:
  Alien(int type, Vector2 pos);
  void Update(int direction);
  void Draw();
  int GetType();
  static void UnloadImages();
  static Texture2D alienImages[3];
  int type;
  Vector2 pos;

private:
};
