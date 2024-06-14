/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initMenu
*/

#include "Menu.hpp"
#include "GameConfig.hpp"

Gui::Menu::Menu(std::shared_ptr<Gui::GameData> gameData): _gameData(gameData)
{
    componentPlayerMode();
    componentSpectatorMode();
    componentSettings();
    componentQuit();
    inputBoxIP();
    inputBoxPort();
    this->_gameData->infoWindow.resolution = {WINDOW_WIDTH, WINDOW_HEIGHT};
    this->_gameData->infoWindow.volume = 50;
}
