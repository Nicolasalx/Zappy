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
        screenMenu();
    } else if (this->_gameData->dataMenu.stateGame == CONNECTION_FAILED_MENU) {
        screenConnectionFailed();
    } else if (this->_gameData->dataMenu.stateGame == IN_SETTINGS) {
        screenSettings();
    }
}

void Gui::Menu::update(const Gui::Event &event)
{
    if (this->_gameData->dataMenu.stateGame == IN_PLAYER_MODE || this->_gameData->dataMenu.stateGame == IN_SPECTATOR_MODE) {
        return;
    }
    handleEvent(event);
    changeScreenMenu();
    resize(event);
}
