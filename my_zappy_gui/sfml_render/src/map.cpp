/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** map
*/

#include "SFMLRenderMap.hpp"

Gui::SFMLRenderMap::SFMLRenderMap()
{
    ;
}

void Gui::SFMLRenderMap::render(const GameData &gameData, sf::RenderWindow &window)
{
    double window_width = window.getSize().x;
    double window_height = window.getSize().y - 75;
    double cell_size = std::min(window_width / gameData.mapSize.x, window_height / gameData.mapSize.y);
    double offset_x = (window_width - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window_height - (cell_size * gameData.mapSize.y)) / 2 + 75;

    for (int i = 0; i < gameData.mapSize.x; ++i) {
        for (int j = 0; j < gameData.mapSize.y; ++j) {
            sprite.setTexture(this->getTexture("bonus/assets/floor.png"));
            sprite.setScale(cell_size / sprite.getLocalBounds().height, cell_size / sprite.getLocalBounds().height);
            sprite.setPosition(offset_x + i * cell_size, offset_y + j * cell_size);
            window.draw(sprite);
        }
    }
}

