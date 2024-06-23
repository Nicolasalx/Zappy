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
    if ((this->_gameData->dataMenu.stateGame != IN_PLAYER_MODE && this->_gameData->dataMenu.stateGame != TRY_PLAYER_MODE) || (_buttonAlreadyClicked && event.isKeyDown)) {
        return;
    }
    resize(event);
    _buttonAlreadyClicked = false;

    for (auto &button: this->_gameData->playerMode.buttonPlayerMode) {
        if (event.isKeyDown && Gui::TextBox::isMouseOnBox(button.button, event.mouse) && button.actPlayer != nullptr) {
            button.button.color = RED_COLOR;
            button.actPlayer();
            _buttonAlreadyClicked = true;
            std::cout << "UPDATE PLAYER MODE\n";
            
        } else {
            button.button.color = WHITE_COLOR;
        }
    }
}
