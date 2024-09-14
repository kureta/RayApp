#include "App.hpp"
#include "raylib.h"
#include <iostream>
#include <unistd.h>

void App::setup() {
  // Window initialization
  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  constexpr int screenWidth = 1280;
  constexpr int screenHeight = 720;

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(screenWidth, screenHeight, "RayApp Example");

  // Ball initialization
  ballPosition = {ballRadius, ballRadius + 40.0};
  ballSpeed = {1200.0, 0.0};

  // Game state initialization
  pause = false;
}

void App::onKeyPressed(const int key_pressed) {
  std::cout << "Key pressed: " << key_pressed << "\n";
  if (key_pressed == KEY_SPACE)
    pause = !pause;
}

void App::onKeyReleased(const int key_released) {
  std::cout << "Key released: " << key_released << "\n";
}

void App::update() {
  if (!pause) {
    double dt_double = dt.count();
    ballPosition.x += ballSpeed.x * dt_double;
    ballPosition.y +=
        ballSpeed.y * dt_double + 0.5 * 4000.0 * dt_double * dt_double;
    ballSpeed.y += 4000.0 * dt_double;

    // Check walls collision for bouncing
    if (ballPosition.x >= static_cast<double>(GetScreenWidth()) - ballRadius ||
        ballPosition.x <= ballRadius) {
      ballSpeed.x *= -1.0;
    }
    if (ballPosition.y >= static_cast<double>(GetScreenHeight()) - ballRadius) {
      ballPosition.y = static_cast<double>(GetScreenHeight()) - ballRadius;
      ballSpeed.y *= -1.0;
    } else if (ballPosition.y <= ballRadius) {
      ballPosition.y = ballRadius;
      ballSpeed.y *= -1.0;
    }
  } else
    framesCounter++;
}

void App::draw() const {
  ClearBackground(RAYWHITE);

  DrawCircleV(ballPosition, ballRadius, MAROON);
  DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20,
           LIGHTGRAY);

  DrawText(TextFormat("t = %.2f", t), 350, 200, 30, GRAY);
  // On pause, we draw a blinking message
  if (pause && framesCounter / 30 % 2)
    DrawText("PAUSED", 350, 200, 30, GRAY);

  DrawFPS(10, 10);
}
