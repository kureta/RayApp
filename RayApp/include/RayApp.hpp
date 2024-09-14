#ifndef RAYAPP_H
#define RAYAPP_H
#include <chrono>
#include <stack>

using seconds = std::chrono::duration<double>;

class RayApp {
public:
  void run();

private:
  void physics_loop();
  void get_keys_released();
  std::stack<int> keys_released;

protected:
  virtual ~RayApp() = default;
  virtual void setup() = 0;
  virtual void update() = 0;
  virtual void draw() const = 0;
  virtual void onKeyPressed(const int key_pressed) = 0;
  virtual void onKeyReleased(const int key_released) = 0;

  const seconds dt{0.01};
  seconds t{0.0};
  int framesCounter = 0;
};

#endif // RAYAPP_H
