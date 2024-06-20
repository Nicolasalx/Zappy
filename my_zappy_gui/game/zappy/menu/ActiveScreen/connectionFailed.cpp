/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** failedToConnect
*/

#include "Menu.hpp"

void Gui::Menu::screenConnectionFailed()
{
    if (_oldState != this->_gameData->dataMenu.stateGame) {
        this->_gameData->dataMenu.componentList.clear();
        this->_gameData->dataMenu.componentsTitle.clear();
        announceRetry();
        goBackToTheMenu();
        _oldState = this->_gameData->dataMenu.stateGame;
    }
}
