/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "zappy_gui.hpp"

Gui::Island::Island(std::shared_ptr<GameState> gameState): _gameState(gameState)
{
    this->addModel("bonus/assets/plateform.obj", "bonus/assets/plateform1.png");
    size = 2.0f;
}