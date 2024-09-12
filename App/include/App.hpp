#ifndef APP_HPP
#define APP_HPP

#include "RayApp.hpp"
#include "raylib.h"

class App final : public RayApp {
public:
  void setup() override;
  void update(seconds t, seconds dt) override;
  void draw() const override;
  void onKeyPressed(int key_pressed) override;
  void onKeyReleased(int key_released) override;

private:
  Vector2 ballPosition = {};
  float ballRadius = 0.0f;
  Vector2 ballSpeed = {};
  bool pause = false;
  int framesCounter = 0;
};

#endif // APP_HPP
