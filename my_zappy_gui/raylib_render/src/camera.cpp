/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "RenderCamera.hpp"

Gui::RenderCamera::RenderCamera()
{
    this->_camera.position = (Vector3){ 0.0, 10.0, 0.0 };
    this->_camera.target = (Vector3){ 50.0, 0.0, 50.0 };
    this->_camera.up = (Vector3){ 0.0, 1.0, 0.0 };
    this->_camera.fovy = 90.0;
    this->_camera.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}

void Gui::RenderCamera::handle_cursor()
{
    if (IsKeyPressed(KEY_P) && !this->cursor) {
        EnableCursor();
        this->cursor = true;
    } else if (IsKeyPressed(KEY_P) && this->cursor) {
        DisableCursor();
        this->cursor = false;
    }
}

void Gui::RenderCamera::update()
{
    if (IsCursorHidden()) {
        UpdateCamera(&this->_camera, CAMERA_FREE);
    }
}