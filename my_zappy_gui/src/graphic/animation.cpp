/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_animation
*/

#include "zappy_gui.hpp"

void Graphic::update_player_pos(player_t &player)
{
    if (frame_time > 0.1f) {
        player.real_pos.x = player.pos.x;
        player.real_pos.y = player.pos.y;
        return;
    }
    if (player.real_pos.x < player.pos.x - 2) {
        player.real_pos.x = player.pos.x;
    }
    if (player.real_pos.x > player.pos.x + 2) {
        player.real_pos.x = player.pos.x;
    }
    if (player.real_pos.y < player.pos.y - 2) {
        player.real_pos.y = player.pos.y;
    }
    if (player.real_pos.y > player.pos.y + 2) {
        player.real_pos.y = player.pos.y;
    }
    if (player.real_pos.x < player.pos.x) {
        player.real_pos.x += 0.05f;
    }
    if (player.real_pos.x > player.pos.x) {
        player.real_pos.x -= 0.05f;
    }
    if (player.real_pos.y < player.pos.y) {
        player.real_pos.y += 0.05f;
    }
    if (player.real_pos.y > player.pos.y) {
        player.real_pos.y -= 0.05f;
    }
}

void Graphic::update_animation(player_t &player)
{
    if (frame_time > 0.1f) {
        player.anim_frame_counter = 32;
        player.real_orientation = player_orientation[player.orientation];
        this->update_player_pos(player);
        return;
    }
    if (player.anim_frame_counter > 31 && player.anim_frame_counter < 151) {
        UpdateModelAnimation(this->model_list[PLAYER], player_animation[player.animation_nbr], player.anim_frame_counter);
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 151) {
        player.anim_frame_counter = 32;
    }
    if (player.anim_frame_counter > 151 && player.anim_frame_counter < 182) {
        UpdateModelAnimation(this->model_list[PLAYER], player_animation[player.animation_nbr], player.anim_frame_counter);
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 182) {
        player.anim_frame_counter = 32;
    }
    if (player_orientation[player.orientation] > player.real_orientation) {
        player.real_orientation += 2;
    }
    if (player_orientation[player.orientation] < player.real_orientation) {
        player.real_orientation -= 2;
    }
    this->update_player_pos(player);
}