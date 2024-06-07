/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "ARayLibModel.hpp"
#include <raylib.h>
#include <raymath.h>

Gui::ARayLibModel::~ARayLibModel()
{
    for (auto &model : _models) {
        UnloadModel(model);
    }
    for (auto &texture : _textures) {
        UnloadTexture(texture);
    }
}

void Gui::ARayLibModel::addModel(std::string model_path, std::string texture_path)
{
    Model model = LoadModel(model_path.c_str());
    Texture2D texture = LoadTexture(texture_path.c_str());
    SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);

    if (model_path.substr(model_path.find_last_of(".") + 1) == "glb") {
        model.transform = MatrixRotateXYZ((Vector3){90.0f * (PI / 180), 0.0f, 0.0f});
    }
    if (model_path.substr(model_path.find_last_of(".") + 1) == "iqm") {
        model.transform = MatrixRotateXYZ((Vector3){-90.0f * (PI / 180), 0.0f, 0.0f});
    }

    _models.push_back(model);
    _textures.push_back(texture);
}

void Gui::ARayLibModel::drawModel(const ModelInfo &modelInfo)
{
    DrawModelEx(_models[modelInfo.index],
        modelInfo.pos,
        modelInfo.rotation_angle,
        modelInfo.rotation,
        modelInfo.scale,
        modelInfo.color);
}