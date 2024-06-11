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

void Gui::SFMLRenderEgg::LoadEggTexture(const GameData &gameData)
{
    textures.resize(gameData.eggList.size());
    for (size_t i = 0; i < gameData.eggList.size(); ++i) {
        if (!textures[i].loadFromFile("bonus/assets/egg.png")) {
            std::cerr << "Error loading egg texture" << std::endl;
            return;
        }
    }
}

void Gui::SFMLRenderEgg::render(const GameData &gameData)
{
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;

    for (size_t i = 0; i < gameData.eggList.size(); ++i) {
        sf::Sprite sprite(textures[i]);
        float egg_scale = cell_size / sprite.getLocalBounds().height * 0.15f;
        sprite.setScale(egg_scale, egg_scale);
        double egg_offset_x = 0.75 * cell_size - (egg_scale * sprite.getLocalBounds().width) / 2;
        double egg_offset_y = 0.5 * cell_size - (egg_scale * sprite.getLocalBounds().height) / 2;
        sprite.setPosition(offset_x + gameData.eggList[i].pos.x * cell_size + egg_offset_x, offset_y + gameData.eggList[i].pos.y * cell_size + egg_offset_y);
        window.draw(sprite);
    }
}
