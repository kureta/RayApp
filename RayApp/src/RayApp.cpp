#include "RayApp.hpp"

#include <chrono>
#include <config.h>

void RayApp::get_keys_released() {
  for (int i = 1; i < MAX_KEYBOARD_KEYS; ++i) {
    if (IsKeyReleased(i))
      keys_released.push(i);
  }
}

void RayApp::physics_loop() {
  using clock = std::chrono::high_resolution_clock;

  auto start = clock::now();
  while (running) {
    // This part keeps the game running at a fixed timestep
    // independent of frame rate (which may vary).
    auto end = clock::now();
    seconds elapsed_seconds = seconds(end - start);

    if (elapsed_seconds < dt)
      std::this_thread::sleep_for(dt - elapsed_seconds);

    while (elapsed_seconds >= dt) {
      update();
      elapsed_seconds -= dt;
      // TODO: find some way to do this without typecasting.
      //       ex. use long duration in nano seconds or what ever is the default
      //       resolution
      start += std::chrono::duration_cast<clock::duration>(dt);
      t.store(t.load() + dt);
    }
  }
}

void RayApp::compute_loop() {
  while (running) {
    update();
  }
}

void RayApp::main_loop() {
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
    framesCounter++;
  }
}
void RayApp::run() {
  setup();
  if (dt.count() > 0.0) {
    physicsThread = std::thread(&RayApp::physics_loop, this);
  } else {
    physicsThread = std::thread(&RayApp::compute_loop, this);
  }

  main_loop();

  stopPhysicsThread();
  CloseWindow();
}

void RayApp::stopPhysicsThread() {
  running = false; // signal the thread to exit
  if (physicsThread.joinable()) {
    physicsThread.join(); // wait for the thread to finish
  }
}

RayApp::~RayApp() { stopPhysicsThread(); }
