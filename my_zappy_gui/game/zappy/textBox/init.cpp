/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initTextBox
*/

#include "TextBox.hpp"

Gui::TextBox::TextBox(std::shared_ptr<Gui::GameData> gameData) : _gameData(gameData)
{
    TextBoxData boxInfo = {(Pos){0.77f, 0.04f}, (Pos){0.21f, 0.1f}, (Pos){0.0f, 0.0f}, (Pos){0.0f, 0.0f}, 0.016, LEFT_BUTTON, {}};
    _gameData->textBox.push_back(boxInfo);
    // TextBoxData boxInfo1 = {0.77f, 0.47f, 0.21f, 0.51f, 0.016, 0, {}};
    TextBoxData boxInfo1 = {(Pos){0.77f, 0.47f}, (Pos){0.21f, 0.40f}, (Pos){0.0f, 0.0f}, (Pos){0.0f, 0.0f}, 0.016, 0, {}};

    _gameData->textBox.push_back(boxInfo1);
    // TextBoxData boxInfo2 = {0.77f, 0.47f, 0.21f, 0.40f, 0.016, 0, {}};
    TextBoxData boxInfo2 = {(Pos){0.77f, 0.57f}, (Pos){0.21f, 0.40f}, (Pos){0.0f, 0.0f}, (Pos){0.0f, 0.0f}, 0.016, 0, {}};
    _gameData->textBox.push_back(boxInfo2);
    // TextBoxData boxInfo3 = {0.01f, 0.57f, 0.15f, 0.40f, 0.016, RIGHT_BUTTON, {}};
    TextBoxData boxInfo3 = {(Pos){0.01f, 0.57f}, (Pos){0.15f, 0.40f}, (Pos){0.0f, 0.0f}, (Pos){0.0f, 0.0f}, 0.016, RIGHT_BUTTON, {}};
    _gameData->textBox.push_back(boxInfo3);
    // TextBoxData boxInfo4 = {0.01f, 0.04f, 0.15f, 0.51f, 0.01, RIGHT_BUTTON, {}};
    TextBoxData boxInfo4 = {(Pos){0.01f, 0.04f}, (Pos){0.15f, 0.51f}, (Pos){0.0f, 0.0f}, (Pos){0.0f, 0.0f}, 0.01, RIGHT_BUTTON, {}};
    _gameData->textBox.push_back(boxInfo4);
}
