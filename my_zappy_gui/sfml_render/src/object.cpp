/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#include "SFMLRenderObject.hpp"

Gui::SFMLRenderObject::SFMLRenderObject()
{
    ;
}

void Gui::SFMLRenderObject::LoadObjectTexture(void)
{
    textures.resize(7);
    for (int i = 0; i < 7; ++i) {
        std::string filename = "bonus/assets/res_" + std::to_string(i + 1) + ".png";
        if (!textures[i].loadFromFile(filename)) {
            std::cerr << "Error loading object texture: " << filename << std::endl;
            return;
        }
    }
}

void Gui::SFMLRenderObject::render(const GameData &gameData)
{
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;

    std::pair<double, double> object_positions[7] = {{0.25, 0.25}, {0.50, 0.25}, {0.75, 0.25}, {0.25, 0.75}, {0.50, 0.75}, {0.75, 0.75}, {0.25, 0.50}};
        for (int i = 0; i < gameData.mapSize.x; ++i) {
            for (int j = 0; j < gameData.mapSize.y; ++j) {
                for (int k = 0; k < 7; ++k) {
                    if (gameData.objectPos[j][i][k] > 0) {
                        sprite.setTexture(textures[k]);
                        float object_scale = cell_size / sprite.getLocalBounds().height * 0.15f;
                        sprite.setScale(object_scale, object_scale);
                        double object_offset_x = object_positions[k].first * cell_size - (object_scale * sprite.getLocalBounds().width) / 2;
                        double object_offset_y = object_positions[k].second * cell_size - (object_scale * sprite.getLocalBounds().height) / 2;
                        sprite.setPosition(offset_x + i * cell_size + object_offset_x, offset_y + j * cell_size + object_offset_y);
                        window.draw(sprite);
                    }
                }
            }
        }
}
