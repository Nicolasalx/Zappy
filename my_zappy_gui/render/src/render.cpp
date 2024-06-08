/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "Raylib.hpp"

void Gui::Raylib::render(const Gui::GameData &gameData)
{
    BeginMode3D(this->camera._camera);
    // BeginShaderMode(light_shader);
    this->skyBox->render();
    this->player->render(gameData);
    this->object->render(gameData);
    // this->particle.drawParticle(this->camera._data);
    this->island->render(gameData);
    this->egg->render(gameData);
    // EndShaderMode();
    EndMode3D();
}
