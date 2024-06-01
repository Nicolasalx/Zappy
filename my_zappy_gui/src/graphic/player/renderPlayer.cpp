/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_draw_player
*/

#include "zappy_gui.hpp"
#include "player.hpp"
#include "infoGame.hpp"

void Gui::Player::draw_player_box(ray_info_t &rayInfo, player_t &player)
{
    if (rayInfo.type == Gui::PLAYER && rayInfo.id == player.n) {
        rayInfo.box.min = (Vector3){player.real_pos.x * Gui::MAP_SCALE -1.0f, 0.0f, player.real_pos.y * Gui::MAP_SCALE - 1.0f};
        rayInfo.box.max = (Vector3){player.real_pos.x * Gui::MAP_SCALE + 1.0f, 3.0f, player.real_pos.y * Gui::MAP_SCALE + 1.0f};
        DrawBoundingBox(rayInfo.box, GREEN);
        DrawModelEx(player_model, (Vector3){player.real_pos.x * Gui::MAP_SCALE, 0.0f, player.real_pos.y * Gui::MAP_SCALE}, (Vector3){0, 1, 0}, player.real_orientation, (Vector3){3, 3, 3}, GREEN);
    }
}

void Gui::Player::draw_player_model(player_t &player)
{
    DrawModelEx(player_model, (Vector3){player.real_pos.x * Gui::MAP_SCALE, 0.0f, player.real_pos.y * Gui::MAP_SCALE}, (Vector3){0, 1, 0}, player.real_orientation, (Vector3){3, 3, 3}, WHITE);
}

void Gui::Player::draw_player(ray_info_t &rayInfo)
{
    for (auto &player : this->_gameState->players_list) {
        update_animation(player);
        if (rayInfo.type == PLAYER && rayInfo.id == player.n) {
            draw_player_box(rayInfo, player);
        } else {
            draw_player_model(player);
        }
    }
}
