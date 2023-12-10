#include "RayApp.hpp"
#include "raylib.h"

void RayApp::main_loop()
{
    setup();
    currentTime = static_cast<float>(GetTime());
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // This part keeps the game running at a fixed timestep
        // independent of frame rate (which may vary).
        const auto newTime = static_cast<float>(GetTime());
        const float frameTime = newTime - currentTime;
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            update(t, dt);
            accumulator -= dt;
            t += dt;
        }

        // This part draws the game at a possibly variable frame rate.
        BeginDrawing();
        draw();
        EndDrawing();
    }

    CloseWindow();
}
