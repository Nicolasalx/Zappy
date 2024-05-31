/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initCamera
*/

#include "zappy_gui.hpp"

void Gui::Graphic::init_camera()
{
    this->camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 90.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}
