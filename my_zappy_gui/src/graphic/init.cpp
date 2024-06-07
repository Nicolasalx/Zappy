/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Graphic.hpp"

Gui::Graphic::Graphic()
{
    this->start(); // Need to pass argc and argv
    this->launch();
    this->loop();
}
