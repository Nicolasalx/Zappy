/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "Raylib.hpp"

void Gui::Raylib::renderGame(const Gui::GameData &gameData)
{
    this->skyBox->render();
    this->player->render(gameData);
    this->object->render(gameData);
    this->particle->render(gameData, this->camera._camera);
    this->island->render(gameData);
    this->egg->render(gameData);
}

void Gui::Raylib::render(const Gui::GameData &gameData)
{
    BeginDrawing();
    BeginMode3D(this->camera._camera);
    if (!gameData.dataMenu.gameIsLaunch) {
        this->menu.render(gameData);
        EndMode3D();
        EndDrawing();
        return;
    }
    renderGame(gameData);
    EndMode3D();
    this->textBoxList->drawAllTextBoxs(gameData);
    EndDrawing();
}
