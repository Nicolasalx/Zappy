/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "SFMLRenderEgg.hpp"

Gui::SFMLRenderEgg::SFMLRenderEgg()
{
    ;
}

void Gui::SFMLRenderEgg::render(const GameData &gameData, sf::RenderWindow &window)
{
    double window_width = window.getSize().x;
    double window_height = window.getSize().y - 75;
    double cell_size = std::min(window_width / gameData.mapSize.x, window_height / gameData.mapSize.y);
    double offset_x = (window_width - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window_height - (cell_size * gameData.mapSize.y)) / 2 + 75;

    for (size_t i = 0; i < gameData.eggList.size(); ++i) {
        sf::Sprite sprite(this->getTexture("bonus/assets/egg.png"));
        float egg_scale = cell_size / sprite.getLocalBounds().height * 0.15f;
        sprite.setScale(egg_scale, egg_scale);
        double egg_offset_x = 0.75 * cell_size - (egg_scale * sprite.getLocalBounds().width) / 2;
        double egg_offset_y = 0.5 * cell_size - (egg_scale * sprite.getLocalBounds().height) / 2;
        sprite.setPosition(offset_x + gameData.eggList[i].pos.x * cell_size + egg_offset_x, offset_y + gameData.eggList[i].pos.y * cell_size + egg_offset_y);
        window.draw(sprite);
    }
}
