/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "Raylib.hpp"
#include "RenderPlayer.hpp"
#include "GameConfig.hpp"

Gui::RenderPlayer::RenderPlayer()
{
    this->addModel(PLAYER_MODEL.data(), PLAYER_TEXTURE.data());

    int animsCount = 5;
    this->player_animation = LoadModelAnimations(PLAYER_MODEL.data(), &animsCount);

    this->player_orientation[1] = 180;
    this->player_orientation[2] = 90;
    this->player_orientation[3] = 0;
    this->player_orientation[4] = 270;

    this->player_color[1] = WHITE;
    this->player_color[2] = RED;
    this->player_color[3] = GREEN;
    this->player_color[4] = BLUE;
    this->player_color[5] = YELLOW;
    this->player_color[6] = PURPLE;
    this->player_color[7] = PINK;
    this->player_color[8] = ORANGE;
}

void Gui::RenderPlayer::drawPlayerModel(const Gui::Player &player)
{
    this->drawModel((ModelInfo){0, (Vector3){player.real_pos.x * Gui::MAP_SCALE, 0.0f, player.real_pos.y * Gui::MAP_SCALE}, (Vector3){0, 1, 0}, 
    (float)player.real_orientation, (Vector3){3 + player.level / 10.0f, 3 + player.level / 10.0f, 3 + player.level / 10.0f}, player_color[player.level]});
}

void Gui::RenderPlayer::render(const Gui::GameData &gameData)
{
    for (auto &player : gameData.playerList) {
        //updateAnimation(player);
        // if (rayInfo.type == PLAYER && rayInfo.id == player.n) {
        //     drawPlayerBox(rayInfo, player);
        // } else {
            drawPlayerModel(player);
        //}
    }
}
