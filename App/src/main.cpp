#include "App.hpp"

int main() {
  std::unique_ptr<App> app = std::make_unique<App>(seconds(1.0 / 120.0), 120);
  app->run();

  return 0;
}
