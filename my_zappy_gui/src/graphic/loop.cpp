/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_loop
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_3D()
{
    BeginMode3D(this->camera._data);
    // BeginShaderMode(light_shader);
    this->draw_sky_box();
    this->player.draw_player(this->rayInfo);
    this->object.render();
    this->particle.draw_particle(this->camera._data);
    this->island.draw_map(this->rayInfo);
    DrawGrid(10, 1.0f);
    // EndShaderMode();
    EndMode3D();
}

void Gui::Graphic::draw_2D()
{
    this->draw_general_info();
    this->draw_player_info();
    this->draw_tile_info();
    this->draw_all_player_level();
}

// void Gui::Graphic::menu()
// {
//     // Button Play
//     // Button Settings
//     // Button Quit
// }

void Gui::Graphic::loop()
{
    while (!WindowShouldClose()) {
        this->event();
        BeginDrawing();
        //if (this->menu.isInMenu) {
        //    this->menu();
        //} else {
        //     this->draw_3D();
        //     this->draw_2D();
        //}
        this->draw_3D();
        this->draw_2D();
        EndDrawing();
    }
    exit(0);
}
