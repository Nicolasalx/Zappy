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
                rayInfo.box.min = (Vector3){i * Gui::MAP_SCALE - 2.2f, -4.2f, j * Gui::MAP_SCALE - 2.2f};
                rayInfo.box.max = (Vector3){i * Gui::MAP_SCALE + 2.2f, 0.2f, j * Gui::MAP_SCALE + 2.2f};
                DrawBoundingBox(rayInfo.box, GREEN);
                DrawModel(this->island_model, (Vector3){i * Gui::MAP_SCALE, -2.0f, j * Gui::MAP_SCALE}, 2.0f, GREEN);
            }
            else {
                DrawModel(this->island_model, (Vector3){i * Gui::MAP_SCALE, -2.0f, j * Gui::MAP_SCALE}, 2.0f, WHITE);
            }
        }
    }
}
