#include "raylib.h"
#include <stdio.h>

int main(void) {
    const int screenWidth = 1080;
    const int screenHeight = 700;

    InitWindow(screenWidth, screenHeight, "Gravity");

    // Circle positions and movement speed
    float x = 100.0f;
    float y = 100.0f;
    float x2 = 300.0f;
    float y2 = 400.0f;

    float radius = 50.0f;
    float Gravity = 9.81f * (5.0f * 5.0f) / (25.0f * 25.0f);

    // Add velocity variables for proper movement
    float vx1 = 100.0f;
    float vy1 = 100.0f;
    float vx2 = -100.0f;
    float vy2 = -100.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // Apply simple “gravity-like” movement
        vy1 += Gravity * dt * 10.0f;
        vy2 -= Gravity * dt * 10.0f;

        // Update positions
        x += vx1 * dt;
        y += vy1 * dt;
        x2 += vx2 * dt;
        y2 += vy2 * dt;

        // --- Screen Collision for Circle 1 ---
        if (x + radius >= screenWidth) {
            x = screenWidth - radius;
            vx1 *= -1;
        } else if (x - radius <= 0) {
            x = radius;
            vx1 *= -1;
        }

        if (y + radius >= screenHeight) {
            y = screenHeight - radius;
            vy1 *= -1;
        } else if (y - radius <= 0) {
            y = radius;
            vy1 *= -1;
        }

        // --- Screen Collision for Circle 2 ---
        if (x2 + radius >= screenWidth) {
            x2 = screenWidth - radius;
            vx2 *= -1;
        } else if (x2 - radius <= 0) {
            x2 = radius;
            vx2 *= -1;
        }

        if (y2 + radius >= screenHeight) {
            y2 = screenHeight - radius;
            vy2 *= -1;
        } else if (y2 - radius <= 0) {
            y2 = radius;
            vy2 *= -1;
        }

        // Print positions if 'J' is pressed
        if (IsKeyDown(KEY_J)) {
            printf("Circle 1: (%f, %f)\n", x, y);
            printf("Circle 2: (%f, %f)\n", x2, y2);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle((int)x, (int)y, radius, RED);
        DrawCircle((int)x2, (int)y2, radius, BLUE);

        EndDrawing();
    }

    CloseWindow();
    printf("Bye\n");
    return 0;
}
