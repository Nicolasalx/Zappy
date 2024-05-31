/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_object()
{
    for (int i = 0; i < this->gameState->map_size.x; i++) {
        for (int j = 0; j < this->gameState->map_size.y; j++) {
            for (int k = 0; k < 7; k++) {
                if (this->gameState->object_pos[j][i][k] != 0) {
                    DrawModel(this->model_list[k], (Vector3){i * SCALE + object_padding[k][0], 0.5f, j * SCALE + object_padding[k][1]}, 0.4f, WHITE);
                }
            }
        }
    }
}