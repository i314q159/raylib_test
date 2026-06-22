#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define InitwinW (1920 / 2)
#define InitwinH (1080 / 2)

int main(void) {
  InitWindow(InitwinW, InitwinH, "Raylib_Test");
  SetTargetFPS(60);
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  const char *text = "Raylib_Test";
  int fontSize = 50; // 居中显示文字的字号大小
  int btnW = 100;    // GUI按钮宽度
  int btnH = 50;     // GUI按钮高度
  int space = 20;    // 文字底部与按钮顶部的垂直间距

  while (!WindowShouldClose()) {
    int winW = GetScreenWidth();
    int winH = GetScreenHeight();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    int textW = MeasureText(text, fontSize);
    // 文字居中坐标
    int textX = winW / 2 - textW / 2;
    int textY = winH / 2 - fontSize / 2;
    DrawText(text, textX, textY, fontSize, VIOLET);

    // 按钮：水平居中，垂直在文字下方
    Rectangle btnRect = {winW / 2.0f - btnW / 2.0f, textY + fontSize + space,
                         btnW, btnH};
    if (GuiButton(btnRect, "START")) {
      TraceLog(LOG_INFO, "按钮被点击");
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
