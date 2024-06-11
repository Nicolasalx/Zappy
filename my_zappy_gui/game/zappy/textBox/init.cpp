/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initTextBox
*/

#include "TextBox.hpp"

Gui::TextBoxData::TextBoxData(float x, float y, float width, float height, float textSize, int state)
{
    this->_pos = {x, y};
    this->_size = {width, height};
    this->_real_pos = {0.0f, 0.0f};
    this->_real_size = {0.0f, 0.0f};
    this->_text_size = textSize;
    this->_buttonPos = {0.0f, 0.0f};
    this->_buttonSize = {0.0f, 0.0f};
    this->_state = state;
    this->_text = {};
}

Gui::TextBox::TextBox(std::shared_ptr<Gui::GameData> gameData) : _gameData(gameData)
{
    TextBoxData boxInfo(0.77f, 0.47f, 0.21f, 0.51f, 0.016, LEFT_BUTTON);
    _gameData->textBox.push_back(boxInfo);
    TextBoxData boxInfo1(0.77f, 0.47f, 0.21f, 0.40f, 0.016, 0);
    _gameData->textBox.push_back(boxInfo1);
    TextBoxData boxInfo2(0.77f, 0.57f, 0.21f, 0.40f, 0.016, 0);
    _gameData->textBox.push_back(boxInfo2);
    TextBoxData boxInfo3(0.01f, 0.57f, 0.15f, 0.40f, 0.016, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo3);
    TextBoxData boxInfo4(0.01f, 0.04f, 0.15f, 0.51f, 0.01, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo4);
}
