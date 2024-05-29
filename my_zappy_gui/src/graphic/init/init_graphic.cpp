/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

Graphic::Graphic(GameState *gameState)
{
    this->gameState = gameState;
    this->init_window();
    this->init_camera();
    this->set_fps(60);
    this->init_sky_box();
    this->init_object();
    this->init_island();
    this->init_player();
    this->init_object_padding();
    this->init_lighting();
    this->init_2D();
    this->player_orientation[1] = 180;
    this->player_orientation[2] = 90;
    this->player_orientation[3] = 0;
    this->player_orientation[4] = 270;
    this->rayInfo.type = 0;
    this->rayInfo.id = 0;
    this->rayInfo.x = 0;
    this->rayInfo.y = 0;
}

Graphic::~Graphic()
{
    CloseWindow();
}
