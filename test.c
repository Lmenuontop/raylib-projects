#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "raylib.h"
//lessgoo

int main() {
    const int screenHeight = 500;
    const int screenWidth = 1000;
    int posx = 100;
    int posy = 100;
    int jumpFrames = 0;
    bool isJumping = false;
    
    InitWindow(screenWidth, screenHeight, "raylib test");
    Texture2D player = LoadTexture("player.png");

	Texture2D enemy = LoadTexture("enemy.png");
    SetTargetFPS(60);
    //how do i set the background
    while (!WindowShouldClose()) {
	if (IsKeyPressed(KEY_UP) && !isJumping) {
	    isJumping = true;
	    jumpFrames = 0;
	}

	// Jump logic
	if (isJumping) {
	    if (jumpFrames < 15) {
		posy -= 3;  // ascending
	    } else if (jumpFrames < 30) {
		posy += 3;  // descending
	    } else {
		isJumping = false;
	    }
	    jumpFrames++;
	}
	// Movement left/right/down
	if (IsKeyDown(KEY_RIGHT)) posx += 10;
	if (IsKeyDown(KEY_LEFT)) posx -= 10;
	if (IsKeyDown(KEY_DOWN) && !isJumping) posy += 10;

	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawTexture(player, posx, posy, WHITE);

		DrawTexture(enemy, 200, 200, WHITE);
	EndDrawing();
    }
    CloseWindow();
    printf("Bye! \n");
    return 0;
}
// end of file.
