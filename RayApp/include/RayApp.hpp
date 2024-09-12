#ifndef RAYAPP_H
#define RAYAPP_H
#include <chrono>

using seconds = std::chrono::duration<double>;

class RayApp {
public:
  virtual ~RayApp() = default;
  virtual void setup() = 0;
  virtual void update(seconds t, seconds dt) = 0;
  virtual void draw() const = 0;
  virtual void KeyPressed(int key_pressed) = 0;
  virtual void KeyReleased(int key_released) = 0;

  void main_loop();
  void physics_loop();

protected:
  const seconds dt{0.01};
};

#endif // RAYAPP_H
