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
    addText(Text{ .contentText = "Failed to connect to the server !", .pos = {0.28, 0.2}, .realPos = {0.28, 0.2}, .fontSize = sizeFontTextMenu, .color = WHITE_COLOR});
    addComponent(ANNOUNCE_RETRY);
}

void Gui::Menu::goBackToTheMenu()
{
    addBox({Box(0.3, 0.6, 0.4, 0.1, WHITE_COLOR)}, "GO BACK TO THE MENU");
    addComponent(GO_BACK_TO_MENU);
}
