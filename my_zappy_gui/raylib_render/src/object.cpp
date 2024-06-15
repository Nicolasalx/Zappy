/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "RenderObject.hpp"
#include "RenderIsland.hpp"

Gui::RenderObject::RenderObject()
{
    this->addModel(Gui::FOOD_MODEL.data(), Gui::FOOD_TEXTURE.data());
    this->addModel(Gui::LINEMATE_MODEL.data(), Gui::LINEMATE_TEXTURE.data());
    this->addModel(Gui::DERAUMERE_MODEL.data(), Gui::DERAUMERE_TEXTURE.data());
    this->addModel(Gui::SIBUR_MODEL.data(), Gui::SIBUR_TEXTURE.data());
    this->addModel(Gui::MENDIANE_MODEL.data(), Gui::MENDIANE_TEXTURE.data());
    this->addModel(Gui::PHIRAS_MODEL.data(), Gui::PHIRAS_TEXTURE.data());
    this->addModel(Gui::THYSTAME_MODEL.data(), Gui::THYSTAME_TEXTURE.data());

    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = std::cos((std::numbers::pi / 180.0) * (i * 50.0));
        this->object_padding[i][1] = std::sin((std::numbers::pi / 180.0) * (i * 50.0));
    }
}

void Gui::RenderObject::render(const Gui::GameData &gameData)
{
    if (gameData.objectPos.size() == 0)
        return;
    for (int i = 0; i < gameData.mapSize.x; i++) {
        for (int j = 0; j < gameData.mapSize.y; j++) {
            for (int k = 0; k < 7; k++) {
                if (gameData.objectPos[j][i][k] != 0) {
                    this->drawModel((ModelInfo){k, (Vector3){i * Gui::RenderIsland::map_scale + this->object_padding[k][0] + 2.0f, 0.5f, j * Gui::RenderIsland::map_scale + this->object_padding[k][1] - 2.0f}, (Vector3){0, 1, 0}, 0, (Vector3){0.4f, 0.4f, 0.4f}, WHITE});
                }
            }
        }
    }
}
