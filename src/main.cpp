#include "echlib.hpp"

int main()
{
    ech::CreateWindow(1280, 720, "Echlib");
    ech::SetFpsLimit(60);
    ech::ClearBackground(ech::Color{ 0.10f, 0.12f, 0.16f, 1.0f });

    while (!ech::WindowShouldClose())
    {
        ech::StartDrawing();
        ech::DrawRectangle(440.0f, 260.0f, 400.0f, 200.0f, ech::LIGHT_BLUE);
        ech::EndDrawing();
    }

    ech::CloseWindow();
    return 0;
}