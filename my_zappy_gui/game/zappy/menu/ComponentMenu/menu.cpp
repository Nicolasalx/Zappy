/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

void Gui::Menu::componentSettings()
{
    addBox({Box(0.1, 0.6, 0.4, 0.1, BLUE_COLOR)}, "SETTINGS");
    addComponent(SETTINGS);
}

void Gui::Menu::componentQuit()
{
    addBox({Box(0.1, 0.8, 0.4, 0.1, BLUE_COLOR)}, "QUIT");
    addComponent(QUIT);
}

void Gui::Menu::componentPlayerMode()
{
    addBox({Box(0.1, 0.2, 0.4, 0.1, BLUE_COLOR)}, "PLAYER MODE");
    addComponent(PLAYER_MODE);
}

void Gui::Menu::componentSpectatorMode()
{
    addBox({Box(0.1, 0.4, 0.4, 0.1, BLUE_COLOR)}, "SPECTATOR MODE");
    addComponent(SPECTATOR_MODE);
}

void Gui::Menu::inputBoxIP()
{
    addBox({Box(0.55, 0.4, 0.4, 0.1, BLUE_COLOR)}, "");
    addComponent(INPUT_BOX_IP);
}

void Gui::Menu::inputBoxPort()
{
    addBox({Box(0.55, 0.6, 0.4, 0.1, BLUE_COLOR)}, "");
    addComponent(INPUT_PORT);
}

void Gui::Menu::inputBoxTeamName()
{
    addBox({Box(0.55, 0.8, 0.4, 0.1, BLUE_COLOR)}, "");
    addComponent(INPUT_TEAM_NAME);
}
