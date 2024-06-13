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
    addComponent(SETTINGS);

    addText(Text("Resolution", {0.2, 0.3}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(SETTINGS);

    addText(Text("Frequency", {0.2, 0.5}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(SETTINGS);

    addText(Text("Volume", {0.2, 0.7}, sizeFontTextMenu, WHITE_COLOR));
    addComponent(SETTINGS);
}
