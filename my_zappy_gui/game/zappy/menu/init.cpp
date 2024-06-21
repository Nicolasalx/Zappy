/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initMenu
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

Gui::Menu::Menu(std::shared_ptr<Gui::GameData> gameData): _gameData(std::move(gameData))
{
    componentPlayerMode();
    componentSpectatorMode();
    componentSettings();
    componentQuit();
    inputBoxIP();
    inputBoxPort();
    inputBoxTeamName();
    this->_gameData->dataMenu.componentsTitle.push_back(Text("IP", {0.55, 0.35}, {0.55, 0.35}, 60, WHITE_COLOR));
    this->_gameData->dataMenu.componentsTitle.push_back(Text("Port", {0.55, 0.55}, {0.55, 0.55}, 60, WHITE_COLOR));
    this->_gameData->dataMenu.componentsTitle.push_back(Text("Team Name", {0.55, 0.75}, {0.55, 0.75}, 60, WHITE_COLOR));
    this->_gameData->infoWindow.resolution = WINDOWED;
    this->_gameData->infoWindow.volume = 10;
}
