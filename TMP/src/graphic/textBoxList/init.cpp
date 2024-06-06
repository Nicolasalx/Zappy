/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init textbox
*/

#include "zappy_gui.hpp"

Gui::TextBox_list::TextBox_list(std::shared_ptr<GameState> gameState, int window_width, int window_height) : _gameState(gameState)
{
    listLevelPlayer.resize(8);
    box_info boxInfo = {0.77f, 0.04f, 0.21f, 0.1f, window_width, window_height, 0.016, LEFT_BUTTON};
    this->_textBoxs.push_back(TextBox(boxInfo));
    boxInfo = {0.77f, 0.47f, 0.21f, 0.51f, window_width, window_height, 0.016, 0};
    this->_textBoxs.push_back(TextBox(boxInfo));
    boxInfo = {0.77f, 0.47f, 0.21f, 0.40f, window_width, window_height, 0.016, 0};
    this->_textBoxs.push_back(TextBox(boxInfo));
    boxInfo = {0.01f, 0.57f, 0.15f, 0.40f, window_width, window_height, 0.016, RIGHT_BUTTON};
    this->_textBoxs.push_back(TextBox(boxInfo));
    boxInfo = {0.01f, 0.04f, 0.15f, 0.51f, window_width, window_height, 0.01, RIGHT_BUTTON};
    this->_textBoxs.push_back(TextBox(boxInfo));
}

void Gui::TextBox_list::resize(int window_width, int window_height)
{
    for (auto &textBox : _textBoxs) {
        textBox.resize(window_width, window_height);
    }
}
