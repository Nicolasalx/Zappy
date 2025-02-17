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

void Gui::RenderPlayer::drawPlayerBox(const Gui::PlayerData &player)
{
    player_box.min = (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale -1.0f, 0.0f, player.real_pos.y * Gui::RenderIsland::map_scale - 1.0f};
    player_box.max = (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale + 1.0f, 3.0f, player.real_pos.y * Gui::RenderIsland::map_scale + 1.0f};
    DrawBoundingBox(player_box, GREEN);
    this->drawModel((ModelInfo){0, (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale, 0.0f, player.real_pos.y * Gui::RenderIsland::map_scale},
    (Vector3){0, 1, 0}, (float)player.real_orientation, (Vector3){3, 3, 3}, GREEN});
}

void Gui::RenderPlayer::drawPlayerModel(const Gui::PlayerData &player)
{   
    this->drawModel((ModelInfo){0, (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale, 0.0, player.real_pos.y * Gui::RenderIsland::map_scale}, (Vector3){0, 1, 0}, 
    (float)player.real_orientation, (Vector3){3 + player.level / 10.0f, 3 + player.level / 10.0f, 3 + player.level / 10.0f}, player_color[player.level]});
}

void Gui::RenderPlayer::updateAnimation(const Gui::PlayerData &player)
{
    if (player.anim_frame_counter > 31 && player.anim_frame_counter < 151) {
        UpdateModelAnimation(_models.at(0), this->player_animation[player.animation_nbr], player.anim_frame_counter);
    }
    if (player.anim_frame_counter > 151 && player.anim_frame_counter < 182) {
        UpdateModelAnimation(_models.at(0), this->player_animation[player.animation_nbr], player.anim_frame_counter);
    }
}

void Gui::RenderPlayer::render(const Gui::GameData &gameData)
{
    for (auto &player : gameData.playerList) {
        updateAnimation(player);
        if (gameData.rayInfo.type == PLAYER && gameData.rayInfo.id == player.n) {
            drawPlayerBox(player);
        } else {
            drawPlayerModel(player);
        }
    }
}
