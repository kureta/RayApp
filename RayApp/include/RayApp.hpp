#ifndef RAYAPP_H
#define RAYAPP_H
#include <chrono>

using seconds = std::chrono::duration<double>;

class RayApp {
public:
  void start();

protected:
  virtual ~RayApp() = default;
  virtual void setup() = 0;
  virtual void update(seconds t, seconds dt) = 0;
  virtual void draw() const = 0;
  virtual void onKeyPressed(int key_pressed) = 0;
  virtual void onKeyReleased(int key_released) = 0;

  const seconds dt{0.01};

private:
  void graphics_loop();
  void physics_loop();
};

#endif // RAYAPP_H
