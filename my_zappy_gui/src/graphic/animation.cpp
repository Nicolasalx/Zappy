/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_animation
*/

#include "zappy_gui.hpp"

void Gui::Player::update_player_pos(player_t &player)
{
    if (player.real_pos.x < player.pos.x) {
        player.real_pos.x += this->_gameState->frame_time * 2;
    }
    if (player.real_pos.x > player.pos.x) {
        player.real_pos.x -= this->_gameState->frame_time * 2;
    }
    if (player.real_pos.y < player.pos.y) {
        player.real_pos.y += this->_gameState->frame_time * 2;
    }
    if (player.real_pos.y > player.pos.y) {
        player.real_pos.y -= this->_gameState->frame_time * 2;
    }
}

void Gui::Player::update_animation(player_t &player)
{
    if (_gameState->frame_time > 0.25f) {
        player.anim_frame_counter = 32;
        player.real_orientation = this->player_orientation[player.orientation];
        player.real_pos.x = player.pos.x;
        player.real_pos.y = player.pos.y;
        return;
    }
    if (player.anim_frame_counter > 31 && player.anim_frame_counter < 151) {
        UpdateModelAnimation(this->player_model, this->player_animation[player.animation_nbr], player.anim_frame_counter);
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 151) {
        player.anim_frame_counter = 32;
    }
    if (player.anim_frame_counter > 151 && player.anim_frame_counter < 182) {
        UpdateModelAnimation(this->player_model, this->player_animation[player.animation_nbr], player.anim_frame_counter);
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 182) {
        player.anim_frame_counter = 32;
    }
    if (this->player_orientation[player.orientation] > player.real_orientation) {
        player.real_orientation += _gameState->frame_time * 200;
    }
    if (this->player_orientation[player.orientation] < player.real_orientation) {
        player.real_orientation -= _gameState->frame_time * 200;
    }
    this->update_player_pos(player);
}