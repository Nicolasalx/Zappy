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

    addText(Text("Resolution", {0.2, 0.37}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addText(Text("Volume", {0.2, 0.57}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(MODIFY_SETTINGS);

    addTriangle(Pos(0.4, 0.4), MODIFY_RESOLUTION);
    addComponent(MODIFY_RESOLUTION);

    addTriangle(Pos(0.4, 0.6), MODIFY_VOLUME);
    addComponent(MODIFY_VOLUME);

    addBox({Box(0.05, 0.85, 0.4, 0.1, BLUE_COLOR)}, "Go back to the menu");
    addComponent(GO_BACK_TO_MENU);
}
