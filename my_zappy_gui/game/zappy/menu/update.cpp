/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateMenu
*/

#include "Menu.hpp"

void Gui::Menu::changeScreenMenu()
{
    if (this->_gameData->dataMenu.stateGame == IN_MENU) {
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
    } else if (this->_gameData->dataMenu.stateGame == TRY_SPECTATOR_MODE) {
        // Loading bar
    } else if (this->_gameData->dataMenu.stateGame == CONNECTION_FAILED_MENU) {
        if (_oldState != this->_gameData->dataMenu.stateGame) {
            this->_gameData->dataMenu.componentList.clear();
            announceRetry();
            goBackToTheMenu();
            _oldState = this->_gameData->dataMenu.stateGame;
        }
    }
}

void Gui::Menu::update(const Gui::Event &event)
{
    handleEvent(event);
    changeScreenMenu();
    resize(event);
}
