/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_animation
*/

#include "zappy_gui.hpp"

void Gui::Graphic::update_player_pos(player_t &player)
{
    if (player.real_pos.x < player.pos.x) {
        player.real_pos.x += this->frame_time * 2;
    }
    if (player.real_pos.x > player.pos.x) {
        player.real_pos.x -= this->frame_time * 2;
    }
    if (player.real_pos.y < player.pos.y) {
        player.real_pos.y += this->frame_time * 2;
    }
    if (player.real_pos.y > player.pos.y) {
        player.real_pos.y -= this->frame_time * 2;
    }
}

void Gui::Graphic::update_animation(player_t &player)
{
    if (frame_time > 0.25f) {
        player.anim_frame_counter = 32;
        player.real_orientation = player_orientation[player.orientation];
        player.real_pos.x = player.pos.x;
        player.real_pos.y = player.pos.y;
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
        player.real_orientation += frame_time * 200;
    }
    if (player_orientation[player.orientation] < player.real_orientation) {
        player.real_orientation -= frame_time * 200;
    }
    this->update_player_pos(player);
}