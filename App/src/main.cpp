#include "App.hpp"
#include <thread>

int main() {
  auto app{App()};

  // TODO: RayApp class should have a `start` method
  //       only that should be called here
  std::thread physicsThread(&App::physics_loop, &app);
  app.main_loop();
  physicsThread.detach();

  return 0;
}
