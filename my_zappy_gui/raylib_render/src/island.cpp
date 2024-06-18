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

float Gui::RenderIsland::map_scale = Gui::MAP_SCALE;
float Gui::RenderIsland::island_size = Gui::ISLAND_SIZE;

Gui::RenderIsland::RenderIsland()
{
    this->addModel(Gui::ISLAND_MODEL.data());
    this->addModel(Gui::ISLAND_LOW_POLY.data());
    this->addModel(Gui::ISLAND_LOW_POLY2.data());
    this->addModel(Gui::ISLAND_PLATFORM.data(), Gui::ISLAND_TEXTURE.data());
}

int Gui::RenderIsland::selectLOD(const Gui::GameData &gameData, float x, float y)
{
    if (modelIndex == 1)
        return 3;
    float distance = abs(gameData.playerPos.x - x) + abs(gameData.playerPos.y - y);
    if (distance > 500.0f)
        return 2;
    if (distance > 200.0f)
        return 1;
    return 0;
}

void Gui::RenderIsland::changeIslandEvent()
{
    if (IsKeyDown(KEY_K))
        Gui::RenderIsland::map_scale += 1.0;
    if (IsKeyDown(KEY_J))
        Gui::RenderIsland::map_scale -= 1.0;
    if (IsKeyPressed(KEY_L)) {
        if (modelIndex == 1) {
            modelIndex = 0;
            Gui::RenderIsland::map_scale = Gui::MAP_SCALE;
            island_size = ISLAND_SIZE;
        }
        else {
            modelIndex = 1;
            Gui::RenderIsland::map_scale = 20.0f;
            island_size = 4.5f;
        }
    }
}

void Gui::RenderIsland::render(const Gui::GameData &gameData)
{
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            if (gameData.rayInfo.type == ISLAND && gameData.rayInfo.x == i && gameData.rayInfo.y == j) {
                _box.min = (Vector3){i * Gui::RenderIsland::map_scale - 1.2f * Gui::RenderIsland::island_size, -Gui::RenderIsland::island_size * 2.2f, j * Gui::RenderIsland::map_scale - 1.2f * Gui::RenderIsland::island_size};
                _box.max = (Vector3){i * Gui::RenderIsland::map_scale + 1.2f * Gui::RenderIsland::island_size, Gui::RenderIsland::island_size * 0.2f, j * Gui::RenderIsland::map_scale + 1.2f * Gui::RenderIsland::island_size};
                DrawBoundingBox(_box, GREEN);
                this->drawModel((ModelInfo){selectLOD(gameData, i * Gui::RenderIsland::map_scale, j * Gui::RenderIsland::map_scale), (Vector3){i * Gui::RenderIsland::map_scale, 0.0f, j * Gui::RenderIsland::map_scale},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::RenderIsland::island_size, Gui::RenderIsland::island_size, Gui::RenderIsland::island_size}, GREEN});
            } else {
                this->drawModel((ModelInfo){selectLOD(gameData, i * Gui::RenderIsland::map_scale, j * Gui::RenderIsland::map_scale), (Vector3){i * Gui::RenderIsland::map_scale, 0.0f, j * Gui::RenderIsland::map_scale},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::RenderIsland::island_size, Gui::RenderIsland::island_size, Gui::RenderIsland::island_size}, WHITE});
            }
        }
    }
}