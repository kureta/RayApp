#include "RayApp.hpp"

#include "raylib.h"
#include <config.h>
#include <cstdio>
#include <thread>

void RayApp::get_keys_released() {
  for (int i = 1; i < MAX_KEYBOARD_KEYS; ++i) {
    if (IsKeyReleased(i))
      keys_released.push(i);
  }
}

void RayApp::physics_loop() {
  while (true) {
    // This part keeps the game running at a fixed timestep
    // independent of frame rate (which may vary).
    auto start = std::chrono::steady_clock::now();
    update();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    if (elapsed_seconds < dt) {
      std::this_thread::sleep_for(dt - elapsed_seconds);
    }

    // TODO: What happens if there is a temporary delay in physics calculations
    //       end dt has to be greater than constant dt?
    t += dt;
  }
}

void RayApp::run() {
  setup();
  std::thread physicsThread(&RayApp::physics_loop, this);

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // IO events are tied to this loop
    if (const int key_pressed = GetKeyPressed();
        key_pressed > 0 && key_pressed < MAX_KEYBOARD_KEYS)
      onKeyPressed(key_pressed);

    get_keys_released();

    while (!keys_released.empty()) {
      onKeyReleased(keys_released.top());
      keys_released.pop();
    }

    // This part draws the game at a possibly variable frame rate.
    BeginDrawing();
    draw();
    EndDrawing();
  }

  CloseWindow();
  physicsThread.detach();
}
