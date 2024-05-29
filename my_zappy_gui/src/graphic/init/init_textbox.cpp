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
    _box = {window_width * _x, window_height * _y, window_width * _width, window_height * _height};
    _color = {200, 200, 255, 100};
}

void TextBox::resize(int window_width, int window_height)
{
    _box = {window_width * _x, window_height * _y, window_width * _width, window_height * _height};
}

void TextBox::draw()
{
    DrawRectangleRec(this->_box, _color);
    DrawRectangleLinesEx(this->_box, 1, WHITE);
}

void Graphic::init_2D()
{
    this->textBoxs.push_back(TextBox(0.78f, 0.04f, 0.2f, 0.1f, window_width, window_height));
    this->textBoxs.push_back(TextBox(0.78f, 0.47f, 0.2f, 0.51f, window_width, window_height));
    this->textBoxs.push_back(TextBox(0.78f, 0.47f, 0.2f, 0.40f, window_width, window_height));
    this->textBoxs.push_back(TextBox(0.01f, 0.07f, 0.2f, 0.40f, window_width, window_height));
}
