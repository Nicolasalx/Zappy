/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updatePlayer
*/

#include "Player.hpp"

void Gui::Player::updatePlayerPos(PlayerData &player)
{
    if (player.real_pos.x < player.pos.x) {
        player.real_pos.x += this->_gameData->frameTime * 2;
    }
    if (player.real_pos.x > player.pos.x) {
        player.real_pos.x -= this->_gameData->frameTime * 2;
    }
    if (player.real_pos.y < player.pos.y) {
        player.real_pos.y += this->_gameData->frameTime * 2;
    }
    if (player.real_pos.y > player.pos.y) {
        player.real_pos.y -= this->_gameData->frameTime * 2;
    }
}

void Gui::Player::updateAnimation(PlayerData &player)
{
    if (_gameData->frameTime > 0.25f) {
        player.anim_frame_counter = 32;
        player.real_orientation = this->playerOrientation[player.orientation];
        player.real_pos.x = player.pos.x;
        player.real_pos.y = player.pos.y;
        return;
    }
    if (player.anim_frame_counter > 31 && player.anim_frame_counter < 151) {
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 151) {
        player.anim_frame_counter = 32;
    }
    if (player.anim_frame_counter > 151 && player.anim_frame_counter < 182) {
        player.anim_frame_counter++;
    }
    if (player.anim_frame_counter == 182) {
        player.anim_frame_counter = 32;
    }
    if (this->playerOrientation[player.orientation] > player.real_orientation) {
        player.real_orientation += _gameData->frameTime * 200;
    }
    if (this->playerOrientation[player.orientation] < player.real_orientation) {
        player.real_orientation -= _gameData->frameTime * 200;
    }
    this->updatePlayerPos(player);
}


void Gui::Player::update(const Gui::Event &event)
{
    (void)event;
    for (auto &player : this->_gameData->playerList) {
        updateAnimation(player);
    }
}
