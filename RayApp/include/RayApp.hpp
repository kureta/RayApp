#ifndef RAYAPP_H
#define RAYAPP_H
#include "raylib.h"
#include <atomic>
#include <chrono>
#include <stack>
#include <thread>

using seconds = std::chrono::duration<double>;

class RayApp {
public:
  explicit RayApp(seconds init_dt = seconds{1.0 / 120.0},
                  int initialTargetFPS = 60)
      : dt{init_dt}, targetFPS{initialTargetFPS} {
    SetTargetFPS(targetFPS);
  }
  void run();

private:
  std::atomic<bool> running{true};
  std::stack<int> keys_released{};
  std::thread physicsThread;
  void get_keys_released();
  void main_loop();
  void physics_loop();
  void stopPhysicsThread();

protected:
  // These methods must be implemented by the user
  virtual ~RayApp();
  virtual void setup() = 0;
  virtual void update() = 0;
  virtual void draw() const = 0;
  virtual void onKeyPressed(int key_pressed) = 0;
  virtual void onKeyReleased(int key_released) = 0;

  // Time step and tartget FPS must be set during initialization
  const seconds dt;
  const int targetFPS;

  // Keep track of time and frames
  std::atomic<seconds> t{seconds(0.0)};
  int framesCounter{0};
};

#endif // RAYAPP_H
