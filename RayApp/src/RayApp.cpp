#include "RayApp.hpp"

#include "raylib.h"
#include <config.h>
#include <stack>

std::stack<int> keys_released;
void get_keys_released() {
  for (int i = 1; i < MAX_KEYBOARD_KEYS; ++i) {
    if (IsKeyReleased(i))
      keys_released.push(i);
  }
}

void RayApp::main_loop() {
  setup();
  currentTime = static_cast<float>(GetTime());
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // This part keeps the game running at a fixed timestep
    // independent of frame rate (which may vary).
    const auto newTime = static_cast<float>(GetTime());
    const float frameTime = newTime - currentTime;
    currentTime = newTime;

    accumulator += frameTime;

    if (const int key_pressed = GetKeyPressed();
        key_pressed > 0 && key_pressed < MAX_KEYBOARD_KEYS)
      KeyPressed(key_pressed);
    get_keys_released();
    while (!keys_released.empty()) {
      KeyReleased(keys_released.top());
      keys_released.pop();
    }
    while (accumulator >= dt) {
      update(t, dt);
      accumulator -= dt;
      t += dt;
    }

    // This part draws the game at a possibly variable frame rate.
    BeginDrawing();
    draw();
    EndDrawing();
  }

  CloseWindow();
}
