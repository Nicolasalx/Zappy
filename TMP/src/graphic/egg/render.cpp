/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "egg.hpp"
#include "zappy_gui.hpp"

void Gui::Egg::render()
{
    for (auto it = this->_gameState->eggs_list.begin(); it != this->_gameState->eggs_list.end(); it++) {
        this->drawModel((ModelInfo){0, (Vector3){it->pos.x * Gui::MAP_SCALE - 2.3f, 1.0f, it->pos.y * Gui::MAP_SCALE - 2.3f}, (Vector3){0, 0, 0}, 0, (Vector3){1, 1, 1}, WHITE});
    }
}
