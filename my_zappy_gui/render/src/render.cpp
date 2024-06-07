/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "Raylib.hpp"

void Gui::Raylib::render(const Gui::GameData &gameData)
{
    BeginMode3D(this->camera._data);
    // BeginShaderMode(light_shader);
    this->skyBox->render(gameData);
    this->player->drawPlayer(this->rayInfo);
    this->object->render();
    this->particle.drawParticle(this->camera._data);
    this->island->drawMap(this->rayInfo);
    this->egg->render();
    // EndShaderMode();
    EndMode3D();
}
