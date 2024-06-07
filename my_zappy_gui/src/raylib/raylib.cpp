/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Raylib
*/

#include "Raylib.hpp"

extern "C"
{
    Gui::IRenderModule *entryPoint(void)
    {
        return new Gui::Raylib();
    }
}

Gui::Raylib::Raylib() : window()
{
    // ! Init window, etc ...
}

Gui::Raylib::~Raylib()
{
    // ! Close window, destroy, etc ...
}
