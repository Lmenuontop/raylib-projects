#include <stdio.h>
#include "raylib.h"
int main() {    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    printf("PNG LOADER \n");

    char path[256];  
    int width=0, height=0;

    printf("Window width: ");
    scanf("%d", &width); // can be blank
    printf("Window height: ");
    scanf("%d", &height); // can be blank
    printf("PNG path: ");
    scanf("%s", path);
    if (width == 0) {
        width = 100;
    }
    if (height == 0) {
        height = 100
    }

    InitWindow(width, height, "png loader");
    SetTargetFPS(60);

    Texture2D png = LoadTexture(path);

    while (!WindowShouldClose()) {
        // Get current window size (since it's resizable)
        int winWidth = GetScreenWidth();
        int winHeight = GetScreenHeight();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Rectangle src = { 0, 0, (float)png.width, (float)png.height };
        Rectangle dest = { 0, 0, (float)winWidth, (float)winHeight };
        Vector2 origin = { 0, 0 };

        DrawTexturePro(png, src, dest, origin, 0.0f, WHITE);

        EndDrawing();
    } 

    UnloadTexture(png);
    CloseWindow();
    return 0;
}
