/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateMenu
*/

#include "Menu.hpp"

void Gui::Menu::changeScreenMenu()
{
    if (this->_gameData->dataMenu.stateGame == TRY_SPECTATOR_MODE) {
        // Loading bar
    } else if (this->_gameData->dataMenu.stateGame == FAIL_SPECTATOR_MODE) {
        this->_gameData->dataMenu.componentList.clear();
        announceRetry();
        goBackToTheMenu();
        // Text : Connection with the server has failed
        // Box / Text : Go Back to the Menu
    }
}

void Gui::Menu::update(const Gui::Event &event)
{
    handleEvent(event);
    changeScreenMenu();
    resize(event);
}
