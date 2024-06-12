/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "RenderTextBox.hpp"

void Gui::RenderTextBox::addText(std::string text, float ypos)
{
    DrawText(text.c_str(), _box.x + _box.width * 0.1f, _box.y + _box.height * ypos, (_box.width * 2) * _boxInfo._text_size, WHITE);
}

void Gui::RenderTextBox::draw()
{
    DrawRectangleRec(this->_box, _color);
    DrawRectangleLinesEx(this->_box, 1, WHITE);
    if (_boxInfo._state != NO_BUTTON) {
        DrawRectangleRec(this->_button, _color);
        DrawRectangleLinesEx(this->_button, 1, WHITE);
    }
    for (size_t i = 0; i < _boxInfo._text.size(); i++) {
        addText(_boxInfo._text[i], ((float)i + 0.5f) / (float)(_boxInfo._text.size() + 0.7f));
    }
}

// bool Gui::TextBox::isClosed()
// {
//     if (_boxInfo.state == CLOSED_RIGHT || _boxInfo.state == CLOSED_LEFT)
//         return true;
//     return false;
// }
