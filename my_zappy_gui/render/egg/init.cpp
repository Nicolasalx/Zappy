/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "RenderEgg.hpp"

Gui::RenderEgg::RenderEgg()
{
    this->addModel(Gui::EGG_MODEL.data(), Gui::EGG_TEXTURE.data());
}
