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

Gui::Raylib::Raylib() : window(),
{
    this->skyBox = std::make_unique<Gui::SkyBox>(gameData);
    this->object = std::make_unique<Gui::Object>(gameData);
    this->player = std::make_unique<Gui::Player>(gameData);
    this->island = std::make_unique<Gui::Island>(gameData);
    this->egg = std::make_unique<Gui::Egg>(gameData);
}

Gui::Raylib::~Raylib()
{
    // ! Close window, destroy, etc ...
}
