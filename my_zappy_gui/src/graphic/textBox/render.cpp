/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "zappy_gui.hpp"

void Gui::TextBox::openClose()
{
    if (CheckCollisionPointRec(GetMousePosition(), _button)) {
        if (state == RIGHT_BUTTON) {
            state = CLOSED_RIGHT;
            resize(_window_width, _window_height);
        }
        else if (state == LEFT_BUTTON) {
            state = CLOSED_LEFT;
            resize(_window_width, _window_height);
        }
        else if (state == CLOSED_RIGHT) {
            state = RIGHT_BUTTON;
            resize(_window_width, _window_height);
        }
        else if (state == CLOSED_LEFT) {
            state = LEFT_BUTTON;
            resize(_window_width, _window_height);
        }
    }
}

void Gui::TextBox::addText(std::string text, float ypos)
{
    DrawText(text.c_str(), _box.x + _window_width * 0.025f, _box.y + this->_box.height * ypos, _window_width / 60, WHITE);
}

void Gui::TextBox::draw()
{
    DrawRectangleRec(this->_box, _color);
    DrawRectangleLinesEx(this->_box, 1, WHITE);
    if (state != NO_BUTTON) {
        DrawRectangleRec(this->_button, _color);
        DrawRectangleLinesEx(this->_button, 1, WHITE);
    }
}

bool Gui::TextBox::isClosed()
{
    if (state == CLOSED_RIGHT || state == CLOSED_LEFT)
        return true;
    return false;
}
