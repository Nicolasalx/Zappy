/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_draw
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_map()
{
    for (int i = 0; i < this->gameState->map_size.x; i++) {
        for (int j = 0; j < this->gameState->map_size.y; j++) {
            if (rayInfo.type == ISLAND && rayInfo.x == i && rayInfo.y == j) {
                this->rayInfo.box.min = (Vector3){i * SCALE - 2.2f, -4.2f, j * SCALE - 2.2f};
                this->rayInfo.box.max = (Vector3){i * SCALE + 2.2f, 0.2f, j * SCALE + 2.2f};
                DrawBoundingBox(this->rayInfo.box, GREEN);
                DrawModel(this->model_list[ISLAND], (Vector3){i * SCALE, -2.0f, j * SCALE}, 2.0f, GREEN);
            }
            else {
                DrawModel(this->model_list[ISLAND], (Vector3){i * SCALE, -2.0f, j * SCALE}, 2.0f, WHITE);
            }
        }
    }
}
