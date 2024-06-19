/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** resize
*/

#include "PlayerMode.hpp"

void Gui::PlayerMode::resize(const Gui::Event &event)
{
    for (auto &button: this->_gameData->playerMode.buttonPlayerMode) {
        button.button.pos = { event.windowSize.width * button.button.realPos.x, event.windowSize.height * button.button.realPos.y };
        button.button.size = { event.windowSize.width * button.button.realSize.width, event.windowSize.height * button.button.realSize.height };
        button.text.pos = { event.windowSize.width * button.text.realPos.x, event.windowSize.height * button.text.realPos.y };
    }
}
