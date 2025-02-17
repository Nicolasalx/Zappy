/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Zappy.hpp"

void Gui::Zappy::update(std::vector<std::string> &messRecv, const Gui::Event &event)
{
    this->_gameData->frameTime = event.frame_time;
    this->_gameData->windowX = event.windowSize.width;
    this->_gameData->windowY = event.windowSize.height;
    this->_gameData->rayInfo = event.rayInfo;
    this->_gameData->playerPos = event.playerPos;
    if (this->_gameData->dataMenu.stateGame == Gui::IN_SPECTATOR_MODE) {
        this->_parser.update(messRecv);
    } else if (this->_gameData->dataMenu.stateGame == Gui::IN_PLAYER_MODE) {
        try {
            this->_playerParser.update(messRecv);
        } catch(...) {
            this->_gameData->dataMenu.stateGame = Gui::CONNECTION_FAILED_MENU;
        }
    }
    this->_playerMode.setSendedMessageQueue(this->_playerParser.getSendedMessage());
    this->_playerMode.update(event);
    this->_island.update(event);
    this->_object.update(event);
    this->_player.update(event);
    this->_egg.update(event);
    this->_textBox.update(event);
    this->_menu.update(event);
}
