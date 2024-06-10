/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

// #include "zappy_gui.hpp"

// void Gui::TextBox::openClose()
// {
//     if (CheckCollisionPointRec(GetMousePosition(), _button)) {
//         if (_boxInfo.state == RIGHT_BUTTON) {
//             _boxInfo.state = CLOSED_RIGHT;
//             resize(_boxInfo.window_width, _boxInfo.window_height);
//         }
//         else if (_boxInfo.state == LEFT_BUTTON) {
//             _boxInfo.state = CLOSED_LEFT;
//             resize(_boxInfo.window_width, _boxInfo.window_height);
//         }
//         else if (_boxInfo.state == CLOSED_RIGHT) {
//             _boxInfo.state = RIGHT_BUTTON;
//             resize(_boxInfo.window_width, _boxInfo.window_height);
//         }
//         else if (_boxInfo.state == CLOSED_LEFT) {
//             _boxInfo.state = LEFT_BUTTON;
//             resize(_boxInfo.window_width, _boxInfo.window_height);
//         }
//     }
// }

// void Gui::TextBox::addText(std::string text, float ypos)
// {
//     DrawText(text.c_str(), _box.x + _boxInfo.window_width * 0.025f, _box.y + this->_box.height * ypos, _boxInfo.window_width * _boxInfo.text_size, WHITE);
// }

// void Gui::TextBox::draw()
// {
//     DrawRectangleRec(this->_box, _color);
//     DrawRectangleLinesEx(this->_box, 1, WHITE);
//     if (_boxInfo.state != NO_BUTTON) {
//         DrawRectangleRec(this->_button, _color);
//         DrawRectangleLinesEx(this->_button, 1, WHITE);
//     }
// }

// bool Gui::TextBox::isClosed()
// {
//     if (_boxInfo.state == CLOSED_RIGHT || _boxInfo.state == CLOSED_LEFT)
//         return true;
//     return false;
// }
