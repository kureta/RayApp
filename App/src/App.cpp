#include "App.hpp"

void App::setup()
{
    // Window initialization
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    dt = 0.01f;

    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - bouncing ball");

    // Ball initialization
    ballPosition = {
        static_cast<float>(GetScreenWidth()) / 2.0f,
        ballRadius + 40.0f
    };
    ballSpeed = {720.0f, 0.0f};
    ballRadius = 20.0f;

    // Game state initialization
    pause = false;
    framesCounter = 0;
}

void App::update(const float t, const float dt)
{
    if (IsKeyPressed(KEY_SPACE)) pause = !pause;

    if (!pause)
    {
        ballPosition.x += ballSpeed.x * dt;
        ballPosition.y += ballSpeed.y * dt + 0.5f * 6400.0f * dt * dt;
        ballSpeed.y += 4000.0f * dt;

        // Check walls collision for bouncing
        if (ballPosition.x >= static_cast<float>(GetScreenWidth()) - ballRadius
            || ballPosition.x <= ballRadius)
        {
            ballSpeed.x *= -1.0f;
        }
        if (ballPosition.y >= static_cast<float>(GetScreenHeight()) - ballRadius)
        {
            ballPosition.y = static_cast<float>(GetScreenHeight()) - ballRadius;
            ballSpeed.y *= -1.0f;
        }
        else if (ballPosition.y <= ballRadius)
        {
            ballPosition.y = ballRadius;
            ballSpeed.y *= -1.0f;
        }
    }
    else framesCounter++;
}

void App::draw() const
{
    ClearBackground(RAYWHITE);

    DrawCircleV(ballPosition, ballRadius, MAROON);
    DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

    // On pause, we draw a blinking message
    if (pause && framesCounter / 30 % 2)
        DrawText("PAUSED", 350, 200, 30, GRAY);

    DrawFPS(10, 10);
}
