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

Gui::Raylib::Raylib() : window(), camera()
{
    this->skyBox = std::make_unique<Gui::RenderSkyBox>();
    this->object = std::make_unique<Gui::RenderObject>();
    this->player = std::make_unique<Gui::RenderPlayer>();
    this->island = std::make_unique<Gui::RenderIsland>();
    this->egg = std::make_unique<Gui::RenderEgg>();
    this->particle = std::make_unique<Gui::RenderParticleSystem>();
    this->textBoxList = std::make_unique<Gui::RenderTextBoxList>();
    this->rayInfo = std::make_unique<Gui::RenderRayInfo>();
    this->endGame = std::make_unique<Gui::RenderEndGame>();
}

Gui::Raylib::~Raylib()
{
    // ! Close window, destroy, etc ...
}
