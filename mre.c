#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  // TODO: FIX the score shower
  // im never gonna do this
  srand(time(NULL) ^ clock());
  int bullet_x_pos = 0;
  int bullet_y_pos = -10;
  bool bullet_fired = false;
  bool dev_mode = false;
  int score = 1;
  int posx = 1080 / 2 - 32 / 2;
  int posy = 720 / 2 - 32 / 2;
  int enemy_posx = rand() % (1080 - 64);
  int enemy_posy = rand() % 100;
  char scorep[20];

  printf("%d \n", score);
  SetTargetFPS(60);
  InitWindow(1080, 720, "simple shooter");
  Texture2D player = LoadTexture("player.png");
  Texture2D enemy = LoadTexture("enemy.png");
  /* temp: */
  Texture2D bullet = LoadTexture("bullet.png");

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_LEFT)) {
      posx -= 10;
    } else if (IsKeyDown(KEY_RIGHT)) {
      posx += 10;
    } else if (IsKeyPressed(KEY_SPACE) && bullet_fired == false) {
      bullet_fired = true;
      bullet_x_pos = posx + player.width / 2 - bullet.width / 2;
      bullet_y_pos = posy - bullet.height;
    }

    if (bullet_fired == true) {

      bullet_y_pos -= 10;
      if (bullet_y_pos < -bullet.height) {
        bullet_fired = false;
        bullet_y_pos = -10;
        score = 0;
      }
    }

    if (bullet_fired) {
      Rectangle bulletRect = {bullet_x_pos, bullet_y_pos, bullet.width,
                              bullet.height};
      Rectangle enemyRect = {enemy_posx, enemy_posy, enemy.width, enemy.height};

      if (CheckCollisionRecs(bulletRect, enemyRect)) {
        // Reset bullet
        bullet_fired = false;
        bullet_y_pos = -10;

        enemy_posx = rand() % (1080 - enemy.width);
        enemy_posy = rand() % 100;

        score++;
        sprintf(scorep, "%d", score);
      }
      if (posx > 1080) {
        posx = 14;
      } else if (posx < 0) {
        posx = 1044;
      }
      enemy_posy += 2;
      if (enemy_posy >= posy) {
        enemy_posy = rand() % 100;
        enemy_posx = rand() % (1080 - 64);
      }

      sprintf(scorep, "%d", score);
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawTexture(player, posx, posy, WHITE);
      DrawTexture(enemy, enemy_posx, enemy_posy, WHITE);
      if (bullet_fired == true) {
        DrawTexture(bullet, bullet_x_pos, bullet_y_pos, WHITE);
      }
      DrawText(scorep, 190, 200, 20, BLACK);
      EndDrawing();
    }

    CloseWindow();
    printf("bye mate...");
    printf("%d \n", score);
  }
}
// end of file
