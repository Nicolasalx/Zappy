/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "Menu.hpp"

void Gui::Menu::screenMenu()
{
    if (_oldState != this->_gameData->dataMenu.stateGame) {
        this->_gameData->dataMenu.componentList.clear();
        componentPlayerMode();
        componentSpectatorMode();
        componentSettings();
        componentQuit();
        inputBoxIP();
        inputBoxPort();
        _oldState = this->_gameData->dataMenu.stateGame;
    }
}
