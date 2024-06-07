/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "RenderEgg.hpp"

Gui::RenderEgg::RenderEgg(const std::string &eggModel, const std::string &eggTexture)
{
    this->addModel(eggModel, eggTexture);
}
