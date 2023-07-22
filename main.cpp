#include "definitions.cpp"
#include "objects.cpp"
#include "raylib.h"
#include "rcamera.h"

// I saw the main function take void as a parameter once in an example so I'll
// do it here blindly
int main(void) {
  int monitor = GetCurrentMonitor();

  const int SCREEN_WIDTH = GetMonitorWidth(monitor);
  const int SCREENT_HEIGHT = GetMonitorHeight(monitor);

  InitWindow(SCREEN_WIDTH, SCREENT_HEIGHT, "3d model import test");

  ToggleFullscreen();

  Player player((Vector3){0, 100, 10}, (Vector3){1, 1.5, 1}, 60,
                (Vector3){0, 0, 0});

  Cube cube((Vector3){0, 0, 0}, (Vector3){2, 4, 2}, RED);

  SetTargetFPS(144);

  DisableCursor();

  while (!WindowShouldClose()) {
    // - - - - - Update - - - - -
    if (IsKeyPressed(KEY_ONE)) {
      player.cameraMode = CAMERA_FREE;
      player.camera.up = (Vector3){0, 1, 0}; // reset roll?
    }
    if (IsKeyPressed(KEY_TWO)) {
      player.cameraMode = CAMERA_FIRST_PERSON;
      player.camera.up = (Vector3){0, 1, 0};
    }
    if (IsKeyPressed(KEY_THREE)) {
      player.cameraMode = CAMERA_THIRD_PERSON;
      player.camera.up = (Vector3){0, 1, 0};
    }
    if (IsKeyPressed(KEY_FOUR)) {
      player.cameraMode = CAMERA_ORBITAL;
      player.camera.up = (Vector3){0, 1, 0};
    }

    player.update();

    // ########################
    // - - - - - Draw - - - - -
    // ########################
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(player.camera);

    player.draw();
    cube.draw();

    DrawGrid(20, 100.0);

    EndMode3D();

    DrawText("click on the hecking box", 10, 30, 20, PURPLE);

    DrawFPS(10, 10);

    EndDrawing();
  }

  // De-Initialize
  CloseWindow(); // this closes window and OpenGL context

  return 0;
}
