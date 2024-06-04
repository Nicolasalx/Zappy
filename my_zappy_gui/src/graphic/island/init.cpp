/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "zappy_gui.hpp"

Gui::Island::Island(std::shared_ptr<GameState> gameState): _gameState(gameState)
{
    island_model = LoadModel("assets/plateform.obj");
    island_texture = LoadTexture("assets/plateform1.png");
    SetTextureFilter(island_texture, TEXTURE_FILTER_TRILINEAR);
    SetMaterialTexture(&island_model.materials[0], MATERIAL_MAP_DIFFUSE, island_texture);
    size = 1.0f;
}
