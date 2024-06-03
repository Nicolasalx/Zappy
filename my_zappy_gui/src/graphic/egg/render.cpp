/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "egg.hpp"
#include "zappy_gui.hpp"

void Gui::Egg::draw()
{
    for (auto it = this->_gameState->eggs_list.begin(); it != this->_gameState->eggs_list.end(); it++) {
        DrawModel(this->_egg_model, (Vector3){it->pos.x * Gui::MAP_SCALE, 0.0f, it->pos.y * Gui::MAP_SCALE}, 1.0f, WHITE);
    }
}