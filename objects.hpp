#include <raylib.h>
#include <raymath.h>

class Player {

public:
  Player(Vector3 position, Vector3 size, int fov, Vector3 target);

  Vector3 handleInput();
  void handlePhysics(Vector3 acceleration);
  void update();
  void draw();

public:
  Vector3 position;
  Vector3 velocity = {0, 0, 0};
  float jumpForce = 1.0;
  Vector3 size;
  float maxSpeed = 0.5;
  Camera3D camera;
  float moveSpeed = 0.01;
  float sensitivity = 0.05;
  int cameraMode = CAMERA_FIRST_PERSON;
};

// move this to separate file later
class Cube {

public:
  Cube(Vector3 position, Vector3 size, Color color);
  void draw();
  void draw_wired();

public:
  Vector3 position;
  Vector3 size;
  Color color;
};
