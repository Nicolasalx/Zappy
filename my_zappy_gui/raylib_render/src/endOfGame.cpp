/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** endOfGame
*/

#include "RenderEndGame.hpp"
#include "RenderIsland.hpp"

Gui::RenderEndGame::RenderEndGame()
{
    addModel(Gui::SPACESHIP_MODEL.data());
}

void Gui::RenderEndGame::render(const GameData &gameData)
{
    drawModel((ModelInfo){0, (Vector3){0, 0, 0}, (Vector3){0, 1, 0}, 0, (Vector3){1.0f, 1.0f, 1.0f}, WHITE});
}