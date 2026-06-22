#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define SCREEN_W (1920 / 2)
#define SCREEN_H (1080 / 2)
#define SCREEN_TITLE "Raylib_Test"

#define UI_TEXT_FONT_SIZE 50
#define UI_BTN_WIDTH 100
#define UI_BTN_HEIGHT 50
#define UI_TEXT_BTN_SPACE 20
#define UI_COLOR_TEXT VIOLET
#define UI_COLOR_BTN_BG VIOLET
#define UI_COLOR_BTN_TEXT WHITE

float DrawCenterText(const char *text, int fontSize, Color textColor) {
    float winW = (float)GetScreenWidth();
    float winH = (float)GetScreenHeight();
    int textW = MeasureText(text, fontSize);

    float textX = winW / 2.0f - (float)textW / 2.0f;
    float textY = winH / 2.0f - (float)fontSize / 2.0f;
    DrawText(text, (int)textX, (int)textY, fontSize, textColor);

    return textY + fontSize;
}

bool DrawCenterButtonBelow(float textBottomY, int btnW, int btnH, int space, const char *btnText) {
    float winW = (float)GetScreenWidth();
    Rectangle btnRect = {winW / 2.0f - (float)btnW / 2.0f, textBottomY + (float)space, (float)btnW, (float)btnH};
    return GuiButton(btnRect, btnText);
}

int main(void) {
    InitWindow(SCREEN_W, SCREEN_H, SCREEN_TITLE);
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(UI_COLOR_BTN_BG));
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(UI_COLOR_BTN_TEXT));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        float textBottom = DrawCenterText("Raylib_Test", UI_TEXT_FONT_SIZE, UI_COLOR_TEXT);
        bool clicked = DrawCenterButtonBelow(textBottom, UI_BTN_WIDTH, UI_BTN_HEIGHT, UI_TEXT_BTN_SPACE, "START");

        if (clicked) {
            TraceLog(LOG_INFO, "BUTTON CLICK");
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
