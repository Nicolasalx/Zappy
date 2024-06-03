/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_loop
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw3D()
{
    BeginMode3D(this->camera._data);
    // BeginShaderMode(light_shader);
    this->drawSkyBox();
    this->player.drawPlayer(this->rayInfo);
    this->object.render();
    this->particle.drawParticle(this->camera._data);
    this->island.drawMap(this->rayInfo);
    this->egg.draw();
    // EndShaderMode();
    EndMode3D();
}

void Gui::Graphic::draw2D()
{
    textBoxs.drawAllTextBoxs(rayInfo);
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
        std::cout << _gameState->eggs_list.size() << std::endl;
        this->event();
        BeginDrawing();
        //if (this->menu.isInMenu) {
        //    this->menu();
        //} else {
        //     this->draw3D();
        //     this->draw2D();
        //}
        this->draw3D();
        this->draw2D();
        EndDrawing();
    }
    exit(0);
}
