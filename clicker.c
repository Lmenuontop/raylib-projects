#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Randomize object spawn position
// make it so that if object 1 is clicked before obj 2 is right clicked it dont give them score. Multitasking aim aimtrainer that ill be horrible at 
void SpawnObject(int *x, int *y) {
  *x = rand() % (1000 - 500);
  *y = rand() % 100;
}

// Handle mouse clicks and object collisions
void HandleClicks(Vector2 mousePos, Rectangle objectRect, Rectangle objectRect2,
                  int *posx, int *posy) {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) &&
      CheckCollisionPointRec(mousePos, objectRect)) {
    TraceLog(LOG_INFO, "object clicked successfully");
    SpawnObject(posx, posy);
  }

  if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && 
      CheckCollisionPointRec(mousePos, objectRect2)) {
    TraceLog(LOG_INFO, "object2 right clicked successfully");
	

  }
}
// Draw both textures on the screen
void DrawObjects(Texture2D object, Texture2D object2, int posx, int posy) {
  DrawTexture(object, posx, posy, WHITE);
  DrawTexture(object2, 45, 300, WHITE);
}
int main() {
  srand(time(NULL) ^ clock());
  const int screenHeight = 500;
  const int screenWidth = 1000;

  InitWindow(screenWidth, screenHeight, "clicker game");

  int posx, posy;
  SpawnObject(&posx, &posy);
  Texture2D object = LoadTexture("object.png");
  Texture2D object2 = LoadTexture("object2.png");

  while (!WindowShouldClose()) {
    Vector2 mousePos = GetMousePosition();

    Rectangle objectRect = {posx, posy, object.width, object.height};
    Rectangle objectRect2 = {45, 300, object2.width, object2.height};

    HandleClicks(mousePos, objectRect, objectRect2, &posx, &posy);
	
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawObjects(object, object2, posx, posy);
    EndDrawing();
  }
  UnloadTexture(object);
  UnloadTexture(object2);
  CloseWindow();

  printf("Bye mate\n");
  return 0;
}

// Word and aonother word
