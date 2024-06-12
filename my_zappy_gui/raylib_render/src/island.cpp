/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "Raylib.hpp"
#include "RenderPlayer.hpp"
#include "RenderIsland.hpp"
#include "GameConfig.hpp"

Gui::RenderIsland::RenderIsland()
{
    this->addModel(Gui::ISLAND_MODEL.data(), Gui::ISLAND_TEXTURE.data());
}

void Gui::RenderIsland::render(const Gui::GameData &gameData)
{
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            if (gameData.rayInfo.type == ISLAND && gameData.rayInfo.x == i && gameData.rayInfo.y == j) {
                _box.min = (Vector3){i * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE, -4.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE};
                _box.max = (Vector3){i * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE, 0.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE};
                DrawBoundingBox(_box, GREEN);
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::MAP_SCALE, -2.0 * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){2.0 * Gui::ISLAND_SIZE, 2.0 * Gui::ISLAND_SIZE, 2.0 * Gui::ISLAND_SIZE}, GREEN});
            } else {
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::MAP_SCALE, -2.0f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){2.0f * Gui::ISLAND_SIZE, 2.0f * Gui::ISLAND_SIZE, 2.0f * Gui::ISLAND_SIZE}, WHITE});
            }
        }
    }
}