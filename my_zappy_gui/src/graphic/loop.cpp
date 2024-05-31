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
    this->draw_general_info();
    this->draw_player_info();
    this->draw_tile_info();
    this->draw_all_player_level();
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
