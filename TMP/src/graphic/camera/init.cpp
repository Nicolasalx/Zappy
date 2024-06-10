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
    this->_data.position = (Vector3){ 0.0, 10.0, 0.0 };
    this->_data.target = (Vector3){ 50.0, 0.0, 50.0 };
    this->_data.up = (Vector3){ 0.0, 1.0, 0.0 };
    this->_data.fovy = 90.0;
    this->_data.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}
