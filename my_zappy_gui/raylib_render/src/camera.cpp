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
        if (IsKeyDown(KEY_W))
            UpdateCameraPro(&this->_camera, (Vector3){GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_S))
            UpdateCameraPro(&this->_camera, (Vector3){-GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_A))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, -GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_D))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_SPACE))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_LEFT_SHIFT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, -GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_LEFT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){-GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_RIGHT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_UP))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, -GetFrameTime() * 30, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_DOWN))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, GetFrameTime() * 30, 0.0f}, 0.0f);
        UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, -GetMouseWheelMove()*2.0f);
        UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetMouseDelta().x*0.05f, GetMouseDelta().y*0.05f, 0.0f}, 0.0f);

        //UpdateCamera(&this->_camera, CAMERA_FREE);
    }
}