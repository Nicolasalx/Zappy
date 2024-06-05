/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initSkyBox
*/

#include "zappy_gui.hpp"

void Gui::Graphic::drawSkyBox()
{
    ClearBackground(RAYWHITE);
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
        DrawModel(this->skyBox->model, (Vector3){0, 0, 0}, 1.0f, WHITE);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}
