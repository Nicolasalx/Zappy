/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** update
*/

#include "PlayerMode.hpp"
#include "TextBox.hpp"

void Gui::PlayerMode::update(const Gui::Event &event)
{
    resize(event);
    for (auto &button: this->_gameData->playerMode.buttonPlayerMode) {
        if (event.isKeyDown && Gui::TextBox::isMouseOnBox(button.button, event.mouse) && button.actPlayer != NULL) {
            button.button.color = RED_COLOR;
            button.actPlayer();
        } else {
            button.button.color = WHITE_COLOR;
        }
    }
}
