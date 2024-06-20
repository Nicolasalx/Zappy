/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** settings
*/

#include "Menu.hpp"

void Gui::Menu::screenSettings()
{
    if (_oldState != this->_gameData->dataMenu.stateGame) {
        this->_gameData->dataMenu.componentList.clear();
        this->_gameData->dataMenu.componentsTitle.clear();

        textSettings();

        _oldState = this->_gameData->dataMenu.stateGame;
    }
}
