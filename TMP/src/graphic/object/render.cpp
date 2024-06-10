/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "zappy_gui.hpp"
#include "object.hpp"

void Gui::Object::render()
{
    for (int i = 0; i < this->_gameState->map_size.x; i++) {
        for (int j = 0; j < this->_gameState->map_size.y; j++) {
            for (int k = 0; k < 7; k++) {
                if (this->_gameState->object_pos[j][i][k] != 0) {
                    this->drawModel((ModelInfo){k, (Vector3){i * Gui::MAP_SCALE + this->object_padding[k][0] + 2.0, 0.5f, j * Gui::MAP_SCALE + this->object_padding[k][1] - 2.0}, (Vector3){0, 1, 0}, 0, (Vector3){0.4f, 0.4f, 0.4f}, WHITE});
                }
            }
        }
    }
}
