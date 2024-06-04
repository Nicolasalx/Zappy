/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "zappy_gui.hpp"

void Gui::Island::drawMap(ray_info_t &rayInfo)
{
    for (int i = 0; i < this->_gameState->map_size.x; i++) {
        for (int j = 0; j < this->_gameState->map_size.y; j++) {
            if (rayInfo.type == ISLAND && rayInfo.x == i && rayInfo.y == j) {
                rayInfo.box.min = (Vector3){i * Gui::MAP_SCALE - 2.2f * this->size, -4.2f * this->size, j * Gui::MAP_SCALE - 2.2f * this->size};
                rayInfo.box.max = (Vector3){i * Gui::MAP_SCALE + 2.2f * this->size, 0.2f * this->size, j * Gui::MAP_SCALE + 2.2f * this->size};
                DrawBoundingBox(rayInfo.box, GREEN);
                DrawModel(this->island_model, (Vector3){i * Gui::MAP_SCALE, -2.0f * this->size, j * Gui::MAP_SCALE}, 2.0f * this->size, GREEN);
            }
            else {
                DrawModel(this->island_model, (Vector3){i * Gui::MAP_SCALE, -2.0f * this->size, j * Gui::MAP_SCALE}, 2.0f * this->size, WHITE);
            }
        }
    }
}
