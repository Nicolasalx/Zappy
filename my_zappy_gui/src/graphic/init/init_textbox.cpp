/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

TextBox::TextBox(float x, float y, float width, float height, int window_width, int window_height)
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

TextBox::TextBox(float x, float y, float width, float height, int window_width, int window_height, int state)
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

void TextBox::resize(int window_width, int window_height)
{
    if (state == NO_BUTTON || state == RIGHT_BUTTON || state == LEFT_BUTTON) {
        _box = {window_width * _x, window_height * _y, window_width * _width, window_height * _height};
        this->_window_width = window_width;
        this->_window_height = window_height;
        if (state == RIGHT_BUTTON) {
            this->_button = {_box.x + _box.width  - (window_width + window_height) * 0.01f, _box.y, (window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
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

void TextBox::open_close()
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

void TextBox::add_text(std::string text, float ypos)
{
    DrawText(text.c_str(), _box.x + _window_width * 0.025f, _box.y + this->_box.height * ypos, _window_width / 60, WHITE);
}

void TextBox::draw()
{
    DrawRectangleRec(this->_box, _color);
    DrawRectangleLinesEx(this->_box, 1, WHITE);
    if (state != NO_BUTTON) {
        DrawRectangleRec(this->_button, _color);
        DrawRectangleLinesEx(this->_button, 1, WHITE);
    }
}

bool TextBox::is_closed()
{
    if (state == CLOSED_RIGHT || state == CLOSED_LEFT)
        return true;
    return false;
}

void Graphic::init_2D()
{
    this->textBoxs.push_back(TextBox(0.77f, 0.04f, 0.21f, 0.1f, window_width, window_height, LEFT_BUTTON));
    this->textBoxs.push_back(TextBox(0.77f, 0.47f, 0.21f, 0.51f, window_width, window_height));
    this->textBoxs.push_back(TextBox(0.77f, 0.47f, 0.21f, 0.40f, window_width, window_height));
    this->textBoxs.push_back(TextBox(0.01f, 0.57f, 0.15f, 0.40f, window_width, window_height, RIGHT_BUTTON));
}
