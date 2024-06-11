/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render textbox
*/

#include "RenderTextBox.hpp"

void Gui::RenderTextBoxList::updateTextBoxs(const GameData &gameData)
{
    while (_textBoxs.size() < gameData.textBox.size()) {
        RenderTextBox newTextBox(gameData.textBox[_textBoxs.size()]);
        _textBoxs.push_back(newTextBox);
    }
    for (size_t i = 0; i < _textBoxs.size(); i++) {
        _textBoxs[i]._box.x = gameData.textBox[i]._real_pos.x;
        _textBoxs[i]._box.y = gameData.textBox[i]._real_pos.y;
        _textBoxs[i]._box.width = gameData.textBox[i]._real_size.x;
        _textBoxs[i]._box.height = gameData.textBox[i]._real_size.y;
        _textBoxs[i]._button.x = gameData.textBox[i]._buttonPos.x;
        _textBoxs[i]._button.y = gameData.textBox[i]._buttonPos.y;
        _textBoxs[i]._button.width = gameData.textBox[i]._buttonSize.x;
        _textBoxs[i]._button.height = gameData.textBox[i]._buttonSize.y;
    }
}

void Gui::RenderTextBoxList::drawAllTextBoxs(const GameData &gameData)
{
    updateTextBoxs(gameData);
    for (auto &textBox : _textBoxs) {
        textBox.draw();
    }
}
