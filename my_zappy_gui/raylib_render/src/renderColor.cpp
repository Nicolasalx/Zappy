/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** renderColor
*/

#include "RenderColor.hpp"

std::map<Gui::GameColor, Color> Gui::RenderColor::_colorMap = {
    { Gui::GameColor::WHITE_COLOR, WHITE },
    { Gui::GameColor::BLACK_COLOR, BLACK },
    { Gui::GameColor::BLUE_COLOR, BLUE },
    { Gui::GameColor::GREEN_COLOR, GREEN },
    { Gui::GameColor::RED_COLOR, RED },
    { Gui::GameColor::GRAY_COLOR, LIGHTGRAY },
    { Gui::GameColor::PURPLE_COLOR, PURPLE }
};

Color Gui::RenderColor::getColorFromGame(const GameColor &gameColor)
{
    return _colorMap.at(gameColor);
}
