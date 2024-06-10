/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init textbox
*/

#include "RenderTextBox.hpp"

void Gui::RenderTextBoxList::resize(int window_width, int window_height)
{
    for (auto &textBox : _textBoxs) {
        textBox.resize(window_width, window_height);
    }
}

void Gui::RenderTextBoxList::updateTextBoxs(GameData &gameData)
{
    while (_textBoxs.size() < gameData.textBox.size()) {
        RenderTextBox newTextBox(gameData.textBox[_textBoxs.size()]);
        _textBoxs.push_back(newTextBox);
    }
}
