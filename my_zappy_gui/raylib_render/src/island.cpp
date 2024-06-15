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
#include <raymath.h>

Gui::RenderIsland::RenderIsland()
{
    this->addModel(Gui::ISLAND_MODEL.data());
    this->addModel(Gui::ISLAND_LOW_POLY.data());
    this->addModel(Gui::ISLAND_LOW_POLY2.data());
}

int Gui::RenderIsland::selectLOD(const Gui::GameData &gameData, float x, float y)
{
    float distance = abs(gameData.playerPos.x - x) + abs(gameData.playerPos.y - y);
    if (distance > 500.0f)
        return 2;
    if (distance > 200.0f)
        return 1;
    return 0;
}

void Gui::RenderIsland::render(const Gui::GameData &gameData)
{
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            if (gameData.rayInfo.type == ISLAND && gameData.rayInfo.x == i && gameData.rayInfo.y == j) {
                _box.min = (Vector3){i * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE, -4.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE};
                _box.max = (Vector3){i * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE, 0.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE};
                DrawBoundingBox(_box, GREEN);
                this->drawModel((ModelInfo){selectLOD(gameData, i * Gui::MAP_SCALE, j * Gui::MAP_SCALE), (Vector3){i * Gui::MAP_SCALE, 0.0f, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::ISLAND_SIZE, Gui::ISLAND_SIZE, Gui::ISLAND_SIZE}, GREEN});
            } else {
                this->drawModel((ModelInfo){selectLOD(gameData, i * Gui::MAP_SCALE, j * Gui::MAP_SCALE), (Vector3){i * Gui::MAP_SCALE, 0.0f, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::ISLAND_SIZE, Gui::ISLAND_SIZE, Gui::ISLAND_SIZE}, WHITE});
            }
        }
    }
}