/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_draw_player
*/

#include "zappy_gui.hpp"
#include "player.hpp"
#include "infoGame.hpp"

void Gui::Player::drawPlayerBox(ray_info_t &rayInfo, player_t &player)
{
    if (rayInfo.type == Gui::PLAYER && rayInfo.id == player.n) {
        rayInfo.box.min = (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale -1.0, 0.0, player.real_pos.y * Gui::RenderIsland::map_scale - 1.0};
        rayInfo.box.max = (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale + 1.0, 3.0, player.real_pos.y * Gui::RenderIsland::map_scale + 1.0};
        DrawBoundingBox(rayInfo.box, GREEN);
        this->drawModel((ModelInfo){0, (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale, 0.0, player.real_pos.y * Gui::RenderIsland::map_scale},
        (Vector3){0, 1, 0}, (float)player.real_orientation, (Vector3){3, 3, 3}, GREEN});
    }
}

void Gui::Player::drawPlayerModel(player_t &player)
{
    this->drawModel((ModelInfo){0, (Vector3){player.real_pos.x * Gui::RenderIsland::map_scale, 0.0, player.real_pos.y * Gui::RenderIsland::map_scale}, (Vector3){0, 1, 0}, 
    (float)player.real_orientation, (Vector3){3 + player.level / 10.0, 3 + player.level / 10.0, 3 + player.level / 10.0}, player_color[player.level]});
}

void Gui::Player::drawPlayer(ray_info_t &rayInfo)
{
    for (auto &player : this->_gameState->players_list) {
        updateAnimation(player);
        if (rayInfo.type == PLAYER && rayInfo.id == player.n) {
            drawPlayerBox(rayInfo, player);
        } else {
            drawPlayerModel(player);
        }
    }
}
