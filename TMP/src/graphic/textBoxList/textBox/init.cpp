/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

Gui::TextBox::TextBox(box_info boxInfo)
{
    _boxInfo = boxInfo;
    _color = {200, 200, 255, 100};
    resize(_boxInfo.window_width, _boxInfo.window_height);
}

void Gui::TextBox::resize(int window_width, int window_height)
{
    if (_boxInfo.state == NO_BUTTON || _boxInfo.state == RIGHT_BUTTON || _boxInfo.state == LEFT_BUTTON) {
        _box = {window_width * _boxInfo.x, window_height * _boxInfo.y, window_width * _boxInfo.width, window_height * _boxInfo.height};
        this->_boxInfo.window_width = window_width;
        this->_boxInfo.window_height = window_height;
        if (_boxInfo.state == RIGHT_BUTTON) {
            this->_button = {
                _box.x + _box.width - (window_width + window_height) * 0.01f,
                _box.y,
                (window_width + window_height) * 0.01f,
                (window_width + window_height) * 0.01f
            };
        }
        if (_boxInfo.state == LEFT_BUTTON) {
            this->_button = {_box.x, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    } else {
        if (_boxInfo.state == CLOSED_RIGHT) {
            _box = {-window_width * _boxInfo.width + (window_width + window_height) * 0.01f, window_height * _boxInfo.y, window_width * _boxInfo.width, window_height * _boxInfo.height};
            this->_boxInfo.window_width = window_width;
            this->_boxInfo.window_height = window_height;
            this->_button = {_box.x + _box.width  - (window_width + window_height) * 0.01f, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
        if (_boxInfo.state == CLOSED_LEFT) {
            _box = {window_width - (window_width + window_height) * 0.01f, window_height * _boxInfo.y, window_width * _boxInfo.width, window_height * _boxInfo.height};
            this->_boxInfo.window_width = window_width;
            this->_boxInfo.window_height = window_height;
            this->_button = {_box.x, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    }
}
