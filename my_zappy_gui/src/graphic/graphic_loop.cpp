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
    this->draw_3D_models();
    DrawGrid(20, 1.0f);
    EndMode3D();
}

void Graphic::draw_2D()
{
    DrawText("Free camera default controls:", window_width / 10 , window_height / 5, (window_height + window_width) / 100, BLACK);
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


