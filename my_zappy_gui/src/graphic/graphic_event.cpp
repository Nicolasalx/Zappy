/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

void Graphic::change_cursor()
{
    if (IsKeyPressed(KEY_P) && !this->cursor) {
        EnableCursor();
        this->cursor = true;
    } else if (IsKeyPressed(KEY_P) && this->cursor) {
        DisableCursor();
        this->cursor = false;
    }
}

void Graphic::event()
{
    if (IsCursorHidden()) UpdateCamera(&this->camera, CAMERA_FREE);
    if (IsKeyPressed(KEY_Z)) {
        this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    }
    this->change_cursor();
}
