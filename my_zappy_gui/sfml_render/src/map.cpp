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
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;

    for (int i = 0; i < gameData.mapSize.x; ++i) {
        for (int j = 0; j < gameData.mapSize.y; ++j) {
            sprite.setTexture(this->getTexture("bonus/assets/floor.png"));
            sprite.setScale(cell_size / sprite.getLocalBounds().height, cell_size / sprite.getLocalBounds().height);
            sprite.setPosition(offset_x + i * cell_size, offset_y + j * cell_size);
            window.draw(sprite);
        }
    }
}
