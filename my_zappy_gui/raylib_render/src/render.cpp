/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "Raylib.hpp"

void Gui::Raylib::renderGame(const Gui::GameData &gameData)
{
    BeginMode3D(this->camera._camera);

    this->skyBox->render();
    this->player->render(gameData);
    this->object->render(gameData);
    this->particle->render(gameData, this->camera._camera);
    this->island->render(gameData);
    this->egg->render(gameData);
    this->rayInfo->render(gameData, this->camera._camera);

    EndMode3D();
    this->textBoxList->render(gameData);
}

void Gui::Raylib::render(const Gui::GameData &gameData)
{
    BeginDrawing();
    this->_ignoreKey = gameData.ignoreKey;
    if (gameData.dataMenu.stateGame != IN_PLAYER_MODE &&
        gameData.dataMenu.stateGame != IN_SPECTATOR_MODE) {
        this->menu.render(gameData);
        EndDrawing();
        return;
    }
    renderGame(gameData);
    EndDrawing();
}
