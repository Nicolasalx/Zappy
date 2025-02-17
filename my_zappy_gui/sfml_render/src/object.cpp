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

void Gui::SFMLRenderObject::render(const GameData &gameData, sf::RenderWindow &window)
{
    double window_width = window.getSize().x;
    double window_height = window.getSize().y - 75;
    double cell_size = std::min(window_width / gameData.mapSize.x, window_height / gameData.mapSize.y);
    double offset_x = (window_width - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window_height - (cell_size * gameData.mapSize.y)) / 2 + 75;

    std::pair<double, double> object_positions[7] = {{0.25, 0.25}, {0.50, 0.25}, {0.75, 0.25}, {0.25, 0.75}, {0.50, 0.75}, {0.75, 0.75}, {0.25, 0.50}};
        for (int i = 0; i < gameData.mapSize.x; ++i) {
            for (int j = 0; j < gameData.mapSize.y; ++j) {
                for (int k = 0; k < 7; ++k) {
                    if (gameData.objectPos[j][i][k] > 0) {
                        sprite.setTexture(this->getTexture("bonus/assets/res_" + std::to_string(k + 1) + ".png"));
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
