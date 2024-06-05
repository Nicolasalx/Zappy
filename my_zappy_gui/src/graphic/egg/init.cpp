/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "egg.hpp"
#include "zappy_gui.hpp"

Gui::Egg::Egg(std::shared_ptr<GameState> gameState) : _gameState(gameState)
{
    this->addModel("bonus/assets/egg.obj", "bonus/assets/texture_egg.png");
}
