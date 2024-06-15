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
                rayInfo.box.min = (Vector3){i * Gui::RenderIsland::map_scale - 2.2f * size, -4.2f * size, j * Gui::RenderIsland::map_scale - 2.2f * size};
                rayInfo.box.max = (Vector3){i * Gui::RenderIsland::map_scale + 2.2f * size, 0.2f * size, j * Gui::RenderIsland::map_scale + 2.2f * size};
                DrawBoundingBox(rayInfo.box, GREEN);
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::RenderIsland::map_scale, -2.0 * size, j * Gui::RenderIsland::map_scale},
                (Vector3){0, 0, 0}, 0, (Vector3){2.0 * size, 2.0 * size, 2.0 * size}, GREEN});
            }
            else {
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::RenderIsland::map_scale, -2.0 * size, j * Gui::RenderIsland::map_scale},
                (Vector3){0, 0, 0}, 0, (Vector3){2.0 * size, 2.0 * size, 2.0 * size}, WHITE});
            }
        }
    }
}
