/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

Gui::TextBox::TextBox(float x, float y, float width, float height, int window_width, int window_height)
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
    _color = {200, 200, 255, 100};
    this->_window_width = window_width;
    this->_window_height = window_height;
    this->state = NO_BUTTON;
    resize(window_width, window_height);
}

Gui::TextBox::TextBox(float x, float y, float width, float height, int window_width, int window_height, int state)
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
    _color = {200, 200, 255, 100};
    this->_window_width = window_width;
    this->_window_height = window_height;
    this->state = state;
    resize(window_width, window_height);
}

void Gui::TextBox::resize(int window_width, int window_height)
{
    if (state == NO_BUTTON || state == RIGHT_BUTTON || state == LEFT_BUTTON) {
        _box = {window_width * _x, window_height * _y, window_width * _width, window_height * _height};
        this->_window_width = window_width;
        this->_window_height = window_height;
        if (state == RIGHT_BUTTON) {
            this->_button = {
                _box.x + _box.width - (window_width + window_height) * 0.01f,
                _box.y,
                (window_width + window_height) * 0.01f,
                (window_width + window_height) * 0.01f
            };
        }
        if (state == LEFT_BUTTON) {
            this->_button = {_box.x, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    } else {
        if (state == CLOSED_RIGHT) {
            _box = {-window_width * _width + (window_width + window_height) * 0.01f, window_height * _y, window_width * _width, window_height * _height};
            this->_window_width = window_width;
            this->_window_height = window_height;
            this->_button = {_box.x + _box.width  - (window_width + window_height) * 0.01f, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
        if (state == CLOSED_LEFT) {
            _box = {window_width - (window_width + window_height) * 0.01f, window_height * _y, window_width * _width, window_height * _height};
            this->_window_width = window_width;
            this->_window_height = window_height;
            this->_button = {_box.x, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    }
}
