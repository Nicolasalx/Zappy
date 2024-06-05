/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "object.hpp"

Gui::Object::Object(std::shared_ptr<Gui::GameState> gameState): _gameState(gameState)
{
    // food
    Model food = LoadModel("bonus/assets/food.glb");
    Texture2D texture = LoadTexture("bonus/assets/texture_food.png");
    SetMaterialTexture(&food.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    food.transform = MatrixRotateXYZ((Vector3){90.0f * (PI / 180), 0.0f, 0.0f});
    this->_modelList.push_back(food);
    // limenate
    Model limenate_model = LoadModel("bonus/assets/linemate.obj");
    Texture2D texture_l = LoadTexture("bonus/assets/texture_linemate.png");
    SetMaterialTexture(&limenate_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_l);
    this->_modelList.push_back(limenate_model);
    // deraumere
    Model deraumere_model = LoadModel("bonus/assets/deraumere.obj");
    Texture2D texture_d = LoadTexture("bonus/assets/texture_deraumere.png");
    SetMaterialTexture(&deraumere_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_d);
    this->_modelList.push_back(deraumere_model);
    // sibur
    Model sibur = LoadModel("bonus/assets/sibur.obj");
    Texture2D texture_s = LoadTexture("bonus/assets/texture_sibur.png");
    SetMaterialTexture(&sibur.materials[0], MATERIAL_MAP_DIFFUSE, texture_s);
    this->_modelList.push_back(sibur);
    // mendiane
    Model mendiane_model = LoadModel("bonus/assets/mendiane.obj");
    Texture2D texture_m = LoadTexture("bonus/assets/texture_mendiane.png");
    SetMaterialTexture(&mendiane_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_m);
    this->_modelList.push_back(mendiane_model);
    // phiras
    Model phiras_model = LoadModel("bonus/assets/phiras.obj");
    Texture2D texture_p = LoadTexture("bonus/assets/texture_phiras.png");
    SetMaterialTexture(&phiras_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_p);
    this->_modelList.push_back(phiras_model);
    // thystame
    Model thystame_model = LoadModel("bonus/assets/thystame.obj");
    Texture2D texture_t = LoadTexture("bonus/assets/texture_thystame.png");
    SetMaterialTexture(&thystame_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_t);
    this->_modelList.push_back(thystame_model);

    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = cos((PI / 180.0f) * (i * 50.0f));
        this->object_padding[i][1] = sin((PI / 180.0f) * (i * 50.0f));
    }
}
