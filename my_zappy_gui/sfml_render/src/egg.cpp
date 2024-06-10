/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "SFMLRenderEgg.hpp"

Gui::SFMLRenderEgg::SFMLRenderEgg(const GameData& gameData)
{
    textures.resize(gameData.playerList.size());
    for (size_t i = 0; i < gameData.playerList.size(); ++i) {
        if (!textures[i].loadFromFile("bonus/assets/astronaute.png")) {
            std::cerr << "Error loading player texture" << std::endl;
            return;
        }
    }
    if (!textures.empty()) {
        sprite.setTexture(textures[0]);
    }
}

void Gui::SFMLRenderEgg::render(const GameData& gameData)
{
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;
    double player_scale = cell_size / sprite.getLocalBounds().height * 0.75f;

    for (size_t i = 0; i < gameData.playerList.size(); ++i) {
        sprite.setTexture(textures[i]);
        sprite.setScale(player_scale, player_scale);
        double sprite_offset_x = 0.5 * cell_size - (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
        double sprite_offset_y = 0.5 * cell_size - (sprite.getLocalBounds().height * sprite.getScale().y) / 2;
        sprite.setPosition(offset_x + gameData.playerList[i].pos.x * cell_size + sprite_offset_x, offset_y + gameData.playerList[i].pos.y * cell_size + sprite_offset_y);
        window.draw(sprite);
    }
}
