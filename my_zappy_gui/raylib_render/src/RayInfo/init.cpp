/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "ARayLibModel.hpp"
#include "RenderRayInfo.hpp"
#include <raylib.h>

Gui::RenderRayInfo::RenderRayInfo()
{
    this->rayInfo.type = 0;
    this->rayInfo.id = 0;
    this->rayInfo.x = 0;
    this->rayInfo.y = 0;
}