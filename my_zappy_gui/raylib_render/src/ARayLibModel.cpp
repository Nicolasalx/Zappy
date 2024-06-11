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
        model.transform = MatrixRotateXYZ((Vector3){90.0 * (std::numbers::pi / 180), 0.0, 0.0});
    }
    if (model_path.substr(model_path.find_last_of(".") + 1) == "iqm") {
        model.transform = MatrixRotateXYZ((Vector3){-90.0 * (std::numbers::pi / 180), 0.0, 0.0});
    }
    _models.push_back(model);
    _textures.push_back(texture);
}

#include <iostream>
#include <filesystem>

void Gui::ARayLibModel::addModel(std::string model_path)
{
    Model model = LoadModel(model_path.c_str());
    std::cout << "EXIT \n";
    std::exit(0);

    std::string path = "./bonus/assets/textures/";
    int index = 0;
    std::cout << "ADD MODEL\n";

    try {
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            std::cout << entry.path().string() << std::endl;
            // Texture2D texture = LoadTexture(entry.path().string().c_str());
            // SetMaterialTexture(&model.materials[index], MATERIAL_MAP_DIFFUSE, texture);
            // _textures.push_back(texture);
            // ++index;
        }
    } catch (const std::filesystem::filesystem_error& err) {
        std::cerr << "Erreur : " << err.what() << std::endl;
    }
    DrawModelEx(_models[0],
            {0, 0, 0},
        {0, 0, 0},
        0,
        {1, 1, 1},
        WHITE);

    // _models.push_back(model);
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
