/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** launch_graphic
*/

#include "zappy_gui.hpp"

void Client::launch_graphic()
{
    Graphic graphic(&this->gameState);
    graphic.loop();
}