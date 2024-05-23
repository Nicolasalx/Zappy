/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_loop
*/

#include "zappy_gui.hpp"

void Graphic::draw_3D()
{
    BeginMode3D(this->camera);
    this->draw_sky_box();
    DrawCube((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires((Vector3){ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(20, 1.0f);
    EndMode3D();
}

void Graphic::draw_2D()
{
    DrawText("Free camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
    DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);
}

void Graphic::loop()
{
    while (!WindowShouldClose()) {
        this->event();
        BeginDrawing();
        this->draw_3D();
        this->draw_2D();
        EndDrawing();
    }
    exit(0);
}


