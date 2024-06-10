/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Core.hpp"

Gui::Core::Core() : gameData(std::make_shared<Gui::GameData>())
{
}

Gui::Core::~Core()
{
    this->renderModule.reset();
    this->clientModule.reset();
    this->gameModule.reset();
    this->renderLoader.close();
    this->clientLoader.close();
}
