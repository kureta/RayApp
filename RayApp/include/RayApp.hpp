#ifndef RAYAPP_H
#define RAYAPP_H
#include <chrono>

using seconds = std::chrono::duration<double>;

class RayApp {
public:
  void run();

private:
  void physics_loop();

protected:
  virtual ~RayApp() = default;
  virtual void setup() = 0;
  virtual void update() = 0;
  virtual void draw() const = 0;
  virtual void onKeyPressed(int key_pressed) = 0;
  virtual void onKeyReleased(int key_released) = 0;

  const seconds dt{0.01};
  seconds t{0.0};
  int framesCounter = 0;
};

#endif // RAYAPP_H
