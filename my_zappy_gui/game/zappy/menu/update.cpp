/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateMenu
*/

#include "Menu.hpp"

void Gui::Menu::update(const Gui::Event &event)
{
    handleEvent(event);
    resize(event);
}
