// check if _OBJECTS_ is declared
#ifndef _OBJECTS_

// Defines _OBJECTS_
#define _OBJECTS_

#include "objects.hpp"
#include "definitions.cpp"
#include "raylib.h"
#include "raymath.h"
#include "rcamera.h"
#include <iostream>

const float GRAVITY = 0.005;

Cube::Cube(Vector3 position, Vector3 size, Color color)
    : position(position), size(size), color(color) {}

void Cube::draw() { DrawCube(position, size.x, size.y, size.z, color); }

void Cube::draw_wired() { DrawCubeWiresV(position, size, color); }

Player::Player(Vector3 position, Vector3 size, int fov, Vector3 target)
    : position(position), size(size) {
  camera = {0};
  camera.position = position;
  camera.target = target;
  camera.up =
      (Vector3){0, 1, 0}; // this is the vector that defines "up" for the camera
  camera.fovy = fov;
  camera.projection = CAMERA_PERSPECTIVE;
}

Vector3 Player::handleInput() {
  // update camera computes movement internally depending on the camera mode
  // Some default standard keyboard/mouse inputs are hardcoed to simplify use
  // For advance camera controls, it's recommended to compute camera movement
  // manually
  // UpdateCamera(&camera, cameraMode);

  Vector3 moveVector = {0, 0, 0};

  if (IsKeyDown(KEY_W)) {
    moveVector.x += moveSpeed;
  }
  if (IsKeyDown(KEY_S)) {
    moveVector.x -= moveSpeed;
  }
  if (IsKeyDown(KEY_A)) {
    moveVector.y -= moveSpeed;
  }
  if (IsKeyDown(KEY_D)) {
    moveVector.y += moveSpeed;
  }
  if (IsKeyDown(KEY_SPACE)) {
    moveVector.y += jumpForce;
  }

  return moveVector;
}

void Player::handlePhysics(Vector3 acceleration) {
  velocity = Vector3Add(velocity, acceleration);
  velocity.z -= GRAVITY;

  if (position.y < (2 * METRE_LENGTH)) {
    velocity.z = 0;
  }

  velocity = Vector3ClampValue(velocity, -maxSpeed, maxSpeed);
}

void Player::update() {
  Vector3 inputVector = handleInput();
  handlePhysics(inputVector);

  Vector3Scale(velocity, GetFrameTime());
  position = Vector3Add(position, velocity);
  std::cout << position.x << ", " << position.y << ", " << position.z
            << std::endl;
  camera.position = position;
}

void Player::draw(){};

#endif // _OBJECTS_
