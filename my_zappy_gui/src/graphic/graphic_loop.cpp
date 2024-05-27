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
    // BeginShaderMode(light_shader);
    this->draw_sky_box();
    this->draw_player();
    this->draw_object();
    this->draw_map();
    DrawGrid(10, 1.0f);
    // EndShaderMode();
    EndMode3D();
}

void Graphic::draw_2D()
{
    DrawText(TextFormat("Number of players: %03i", this->gameState->players_list.size()), window_width * 0.77, window_height / 20, window_width / 60, WHITE);
    // DrawRectangleRec(textBoxs.front(), LIGHTGRAY);
    DrawFPS(10, 10);
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


