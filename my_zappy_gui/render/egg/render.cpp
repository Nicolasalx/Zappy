/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "RenderEgg.hpp"

void Gui::RenderEgg::render(const Gui::GameData &gameData)
{
    for (auto it = gameData.eggList.begin(); it != gameData.eggList.end(); ++it) {
        this->drawModel(
            (Gui::ModelInfo){0,
                {
                    it->pos.x * Gui::MAP_SCALE - 2.3f,
                    1.0f,
                    it->pos.y * Gui::MAP_SCALE - 2.3f
                },
                {0, 0, 0}, 0, {1, 1, 1}, WHITE});
    }
}
