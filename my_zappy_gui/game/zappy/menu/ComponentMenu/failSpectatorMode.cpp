/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** failSpectatorMode
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

void Gui::Menu::announceRetry()
{
    //addBox({Box(0.1, 0.4, 0.4, 0.1, BLUE_COLOR)}, "FAILED TO CONNECT TO THE SERVER");
    addText(Text("Failed to connect to the server !", {0.2, 0.2}, 20, WHITE_COLOR));
    addComponent(ANNOUNCE_RETRY);
}

void Gui::Menu::goBackToTheMenu()
{
    addBox({Box(0.5, 0.6, 0.4, 0.1, BLUE_COLOR)}, "GO BACK TO THE MENU");
    addComponent(GO_BACK_TO_MENU);
}
