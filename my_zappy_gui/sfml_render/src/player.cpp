/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#include "SFMLRenderPlayer.hpp"

Gui::SFMLRenderPlayer::SFMLRenderPlayer()
{
    ;
}

void Gui::SFMLRenderPlayer::render(const GameData &gameData, sf::RenderWindow &window)
{
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;
    double player_scale = cell_size / sprite.getLocalBounds().height * 0.75f;

    for (size_t i = 0; i < gameData.playerList.size(); ++i) {
        sprite.setTexture(this->getTexture("bonus/assets/astronaute.png"));
        sprite.setScale(player_scale, player_scale);
        double sprite_offset_x = 0.5 * cell_size - (sprite.getLocalBounds().width * sprite.getScale().x) / 2;
        double sprite_offset_y = 0.5 * cell_size - (sprite.getLocalBounds().height * sprite.getScale().y) / 2;
        sprite.setPosition(offset_x + gameData.playerList[i].real_pos.x * cell_size + sprite_offset_x, offset_y + gameData.playerList[i].real_pos.y * cell_size + sprite_offset_y);
        std::cout << "pos x: " << gameData.playerList[i].pos.x << " , real pos_x: " << gameData.playerList[i].real_pos.x << std::endl;
        window.draw(sprite);
    }
}
