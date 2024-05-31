/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "zappy_gui.hpp"

Gui::Island::Island(std::vector<Model> &modelList)
{
    Model island = LoadModel("assets/plateform.obj");
    Texture2D texture = LoadTexture("assets/plateform1.png");

    SetTextureFilter(texture, TEXTURE_FILTER_TRILINEAR);
    SetMaterialTexture(&island.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    modelList.push_back(island);
}
