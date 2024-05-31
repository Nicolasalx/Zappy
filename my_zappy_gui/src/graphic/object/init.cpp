/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "zappy_gui.hpp"

void Gui::Graphic::init_object()
{
    // food
    Model food = LoadModel("assets/food.glb");
    Texture2D texture = LoadTexture("assets/texture_food.png");
    SetMaterialTexture(&food.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    food.transform = MatrixRotateXYZ((Vector3){90.0f * (PI / 180), 0.0f, 0.0f});
    this->model_list.push_back(food);
    // limenate
    Model limenate_model = LoadModel("assets/linemate.obj");
    Texture2D texture_l = LoadTexture("assets/texture_linemate.png");
    SetMaterialTexture(&limenate_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_l);
    this->model_list.push_back(limenate_model);
    // deraumere
    Model deraumere_model = LoadModel("assets/deraumere.obj");
    Texture2D texture_d = LoadTexture("assets/texture_deraumere.png");
    SetMaterialTexture(&deraumere_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_d);
    this->model_list.push_back(deraumere_model);
    // sibur
    Model sibur = LoadModel("assets/sibur.obj");
    Texture2D texture_s = LoadTexture("assets/texture_sibur.png");
    SetMaterialTexture(&sibur.materials[0], MATERIAL_MAP_DIFFUSE, texture_s);
    this->model_list.push_back(sibur);
    // mendiane
    Model mendiane_model = LoadModel("assets/mendiane.obj");
    Texture2D texture_m = LoadTexture("assets/texture_mendiane.png");
    SetMaterialTexture(&mendiane_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_m);
    this->model_list.push_back(mendiane_model);
    // phiras
    Model phiras_model = LoadModel("assets/phiras.obj");
    Texture2D texture_p = LoadTexture("assets/texture_phiras.png");
    SetMaterialTexture(&phiras_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_p);
    this->model_list.push_back(phiras_model);
    // thystame
    Model thystame_model = LoadModel("assets/thystame.obj");
    Texture2D texture_t = LoadTexture("assets/texture_thystame.png");
    SetMaterialTexture(&thystame_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_t);
    this->model_list.push_back(thystame_model);
}

void Gui::Graphic::init_object_padding()
{
    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = cos((PI / 180.0f) * (i * 50.0f));
        this->object_padding[i][1] = sin((PI / 180.0f) * (i * 50.0f));
    }
}
