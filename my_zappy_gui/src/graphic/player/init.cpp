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
    this->addModel("assets/Astronaut.iqm", "assets/AstronautColor.png");

    int animsCount = 5;
    this->player_animation = LoadModelAnimations("assets/Astronaut.iqm", &animsCount);

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
