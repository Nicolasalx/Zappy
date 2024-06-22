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
        this->_gameData->dataMenu.dataConnection.ip.clear();
        this->_gameData->dataMenu.dataConnection.port.clear();
        this->_gameData->dataMenu.dataConnection.teamName.clear();
        this->_gameData->dataMenu.dataConnection.needToClearBuffer = true;
        _oldState = this->_gameData->dataMenu.stateGame;
    }
}
