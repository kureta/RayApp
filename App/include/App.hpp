#ifndef APP_HPP
#define APP_HPP

#include "RayApp.hpp"
#include "raylib.h"

class App final : public RayApp {
public:
  void setup() override;
  void update() override;
  void draw() const override;
  void onKeyPressed(int key_pressed) override;
  void onKeyReleased(int key_released) override;

private:
  Vector2 ballPosition = {};
  static constexpr double ballRadius{20.0};
  Vector2 ballSpeed = {};
  bool pause = false;
};

#endif // APP_HPP
