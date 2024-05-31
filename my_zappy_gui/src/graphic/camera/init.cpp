/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initCamera
*/

#include "zappy_gui.hpp"
#include "camera.hpp"

Gui::Camera::Camera()
{
    this->_data.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    this->_data.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->_data.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->_data.fovy = 90.0f;
    this->_data.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}
