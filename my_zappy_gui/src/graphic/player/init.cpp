/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "zappy_gui.hpp"
#include "player.hpp"

Gui::Player::Player(std::shared_ptr<GameState> gameState): _gameState(gameState)
{
    player_model = LoadModel("assets/Astronaut.iqm");
    player_texture = LoadTexture("assets/AstronautColor.png");
    SetMaterialTexture(&player_model.materials[0], MATERIAL_MAP_DIFFUSE, player_texture);
    player_model.transform = MatrixRotateXYZ((Vector3){-90.0f * (PI / 180), 0.0f, 0.0f});

    int animsCount = 5;
    this->player_animation = LoadModelAnimations("assets/Astronaut.iqm", &animsCount);

    this->player_orientation[1] = 180;
    this->player_orientation[2] = 90;
    this->player_orientation[3] = 0;
    this->player_orientation[4] = 270;
}
