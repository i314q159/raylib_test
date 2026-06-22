#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define SCREEN_H (1920 / 2)
#define SCREEN_W (1080 / 2)

int main(void) {
  InitWindow(SCREEN_H, SCREEN_W, "Raylib_Test");
  SetTargetFPS(60);
  SetWindowState(FLAG_WINDOW_RESIZABLE);

  const char *text = "Raylib_Test";
  int fontSize = 50; // 居中显示文字的字号大小

  int btnW = 100; // 按钮宽度
  int btnH = 50;  // 按钮高度

  int space = 20; // 文字底部与按钮顶部的垂直间距

  // 每帧绘制
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // 文字居中
    int textW = MeasureText(text, fontSize);
    int winW = GetScreenWidth();
    int winH = GetScreenHeight();
    int textX = winW / 2.0f - textW / 2.0f;
    int textY = winH / 2.0f - fontSize / 2.0f;
    DrawText(text, textX, textY, fontSize, VIOLET);

    // 计算按钮矩形坐标：水平居中，垂直在文字下方
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(VIOLET));
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(WHITE));
    Rectangle btnRect = {
        winW / 2.0f - btnW / 2.0f, // X：窗口宽度一半 - 按钮宽一半 = 水平居中
        textY + fontSize + space,  // Y：上方文字Y + 文字高度 + 间距
        btnW,                      // 按钮宽度
        btnH                       // 按钮高度
    };
    // 绘制按钮，点击返回true
    if (GuiButton(btnRect, "START")) {
      TraceLog(LOG_INFO, "按钮被点击");
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
