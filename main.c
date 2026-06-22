#include "raylib.h"

int main(void) {
  InitWindow(800, 400, "test");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("test", 400, 150, 50, BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
