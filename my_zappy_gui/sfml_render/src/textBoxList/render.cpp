/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render textbox
*/

#include "SFMLRenderTextBox.hpp"

void Gui::SFMLRenderTextBoxList::updateTextBoxs(const GameData &gameData)
{
    while (_textBoxs.size() < gameData.textBox.size()) {
        SFMLRenderTextBox newTextBox(gameData.textBox[_textBoxs.size()]);
        _textBoxs.push_back(newTextBox);
    }
    for (size_t i = 0; i < gameData.textBox.size(); i++) {
        if (gameData.textBox[i]._text.size() != _textBoxs[i]._boxInfo._text.size()) {
            _textBoxs[i]._boxInfo._text = gameData.textBox[i]._text;
        }
    }
    for (size_t i = 0; i < _textBoxs.size(); i++) {
        _textBoxs[i]._box.left = gameData.textBox[i]._real_pos.x;
        _textBoxs[i]._box.top = gameData.textBox[i]._real_pos.y;
        _textBoxs[i]._box.width = gameData.textBox[i]._real_size.x;
        _textBoxs[i]._box.height = gameData.textBox[i]._real_size.y;
        _textBoxs[i]._button.left = gameData.textBox[i]._buttonPos.x;
        _textBoxs[i]._button.top = gameData.textBox[i]._buttonPos.y;
        _textBoxs[i]._button.width = gameData.textBox[i]._buttonSize.x;
        _textBoxs[i]._button.height = gameData.textBox[i]._buttonSize.y;
        _textBoxs[i]._boxInfo._state = gameData.textBox[i]._state;
        for (size_t j = 0; j < gameData.textBox[i]._text.size(); j++) {
            _textBoxs[i]._boxInfo._text[j] = gameData.textBox[i]._text[j];
        }
    }
}


void Gui::SFMLRenderTextBoxList::drawAllTextBoxs(sf::RenderWindow &window, const sf::Font &font, const GameData &gameData)
{
    updateTextBoxs(gameData);
    for (auto &textBox : _textBoxs) {
        textBox.draw(window, font);
    }
}
