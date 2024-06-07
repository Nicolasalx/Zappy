/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "RenderObject.hpp"

Gui::RenderObject::RenderObject()
{
    this->addModel(Gui::FOOD_MODEL.data(), Gui::FOOD_TEXTURE.data());

    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = cos((PI / 180.0f) * (i * 50.0f));
        this->object_padding[i][1] = sin((PI / 180.0f) * (i * 50.0f));
    }
}

void Gui::RenderObject::render(const Gui::GameData &gameData)
{
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            for (int k = 0; k < 7; k++) {
                if (gameData.objectPos[j][i][k] != 0) {
                    this->drawModel((ModelInfo){k, (Vector3){i * Gui::MAP_SCALE + this->object_padding[k][0] + 2.0f, 0.5f, j * Gui::MAP_SCALE + this->object_padding[k][1] - 2.0f}, (Vector3){0, 1, 0}, 0, (Vector3){0.4f, 0.4f, 0.4f}, WHITE});
                }
            }
        }
    }
}
