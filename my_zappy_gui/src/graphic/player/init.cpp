/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "zappy_gui.hpp"

void Gui::Graphic::init_player()
{
    Model player = LoadModel("assets/Astronaut.iqm");
    Texture2D texture = LoadTexture("assets/AstronautColor.png");
    SetMaterialTexture(&player.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    player.transform = MatrixRotateXYZ((Vector3){-90.0f * (PI / 180), 0.0f, 0.0f});
    this->model_list.push_back(player);

    int animsCount = 5;
    this->player_animation = LoadModelAnimations("assets/Astronaut.iqm", &animsCount);
}