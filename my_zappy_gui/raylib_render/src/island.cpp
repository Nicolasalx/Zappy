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
}

void Gui::RenderIsland::render(const Gui::GameData &gameData)
{
    // if (gameData.islandInfo.size() > 0 && _islandTransform.size() == 0) {
    //     for (int i = 0; i < gameData.islandInfo.size(); i++) {
    //         Matrix transform;
    //         float scale = Gui::ISLAND_SIZE;
    //         Vector3 pos = {gameData.islandInfo[i].x * Gui::MAP_SCALE, 0.0f, gameData.islandInfo[i].y * Gui::MAP_SCALE};
    //         Vector3 rotation = {0, 0, 0};
    //         transform = MatrixMultiply(MatrixRotateXYZ(rotation), MatrixScale(scale, scale, scale));
    //         transform = MatrixMultiply(MatrixTranslate(pos.x, pos.y, pos.z), transform);
    //         _islandTransform.push_back(transform);
    //     }
    // }
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            if (gameData.rayInfo.type == ISLAND && gameData.rayInfo.x == i && gameData.rayInfo.y == j) {
                _box.min = (Vector3){i * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE, -4.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE - 2.2f * Gui::ISLAND_SIZE};
                _box.max = (Vector3){i * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE, 0.2f * Gui::ISLAND_SIZE, j * Gui::MAP_SCALE + 2.2f * Gui::ISLAND_SIZE};
                DrawBoundingBox(_box, GREEN);
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::MAP_SCALE, 0.0f, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::ISLAND_SIZE, Gui::ISLAND_SIZE, Gui::ISLAND_SIZE}, GREEN});
            } else {
                this->drawModel((ModelInfo){0, (Vector3){i * Gui::MAP_SCALE, 0.0f, j * Gui::MAP_SCALE},
                (Vector3){0, 0, 0}, 0, (Vector3){Gui::ISLAND_SIZE, Gui::ISLAND_SIZE, Gui::ISLAND_SIZE}, WHITE});
            }
        }
    }
    // std::cout << "ISLAND SIZE: " << gameData.islandInfo.size() << std::endl;
    // std::cout << "ISLAND TRANSFORM SIZE: " << _islandTransform.size() << std::endl;
    //             DrawMeshInstanced(_models[0].meshes[0], _models[0].materials[0], _islandTransform.data(), gameData.islandInfo.size());

}