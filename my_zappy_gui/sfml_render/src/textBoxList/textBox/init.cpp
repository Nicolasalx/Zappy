/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "SFMLRenderTextBox.hpp"

Gui::SFMLRenderTextBox::SFMLRenderTextBox(TextBoxData boxInfo) : _boxInfo(boxInfo)
{
    _color = {200, 200, 255, 100};
}
