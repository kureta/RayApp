#ifndef RAYAPP_H
#define RAYAPP_H

class RayApp {
public:
  virtual ~RayApp() = default;
  virtual void setup() = 0;
  virtual void update(float t, float dt) = 0;
  virtual void draw() const = 0;

  virtual void KeyPressed(int key_pressed) = 0;
  virtual void KeyReleased(int key_released) = 0;
  void main_loop();
  void physics_loop();

protected:
  const float dt = 0.01f;

private:
  float t = 0.0f;
  float currentTime = 0.0f;
  float accumulator = 0.0f;
};

#endif // RAYAPP_H
