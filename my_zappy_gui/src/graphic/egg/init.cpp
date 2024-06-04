/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#include "egg.hpp"
#include "zappy_gui.hpp"

Gui::Egg::Egg(std::shared_ptr<GameState> gameState)
{
    this->_gameState = gameState;
    this->_egg_model = LoadModel("assets/egg.obj");
    this->_egg_texture = LoadTexture("assets/texture_egg.png");
    SetTextureFilter(this->_egg_texture, TEXTURE_FILTER_TRILINEAR);
    SetMaterialTexture(&this->_egg_model.materials[0], MATERIAL_MAP_DIFFUSE, this->_egg_texture);
}
