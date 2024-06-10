/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sfml
*/

#include "SFMLRender.hpp"

extern "C"
{
    Gui::IRenderModule *entryPoint(void)
    {
        return new Gui::SFMLRender();
    }
}

Gui::SFMLRender::SFMLRender() : window()
{
    // this->skyBox = std::make_unique<Gui::RenderSkyBox>();
    // this->object = std::make_unique<Gui::RenderObject>();
    this->player = std::make_unique<Gui::SFMLRenderPlayer>();
    // this->island = std::make_unique<Gui::RenderIsland>();
    // this->egg = std::make_unique<Gui::RenderEgg>();
    // this->particle = std::make_unique<Gui::RenderParticleSystem>();
}
