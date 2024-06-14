/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** settings
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

void Gui::Menu::textSettings()
{
    addText(Text("Settings", {0.1, 0.1}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addText(Text("Resolution", {0.2, 0.3}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addText(Text("Frequency", {0.2, 0.5}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addText(Text("Volume", {0.2, 0.7}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addTriangle(Pos(0.4, 0.33));
    addComponent(MODIFY_SETTINGS);

    addTriangle(Pos(0.4, 0.53));
    addComponent(MODIFY_SETTINGS);

    addTriangle(Pos(0.4, 0.73));
    addComponent(MODIFY_SETTINGS);

    addBox({Box(0.05, 0.85, 0.4, 0.1, BLUE_COLOR)}, "Go back to the menu");
    addComponent(GO_BACK_TO_MENU);
}
