/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** gui
*/

#include "Zappy.hpp"

Gui::Zappy::Zappy()
{

}

extern "C"
{
    Gui::IGameModule *entryPoint(void)
    {
        return new Gui::Zappy();
    }
}

Gui::Zappy::~Zappy()
{
    
}
