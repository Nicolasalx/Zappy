/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initSkyBox
*/

#include "zappy_gui.hpp"
#include "skyBox.hpp"

Gui::SkyBox::SkyBox(std::shared_ptr<GameState> gameState): _gameState(gameState)
{
    Mesh cube = GenMeshCube(1.0, 1.0, 1.0);
    this->model = LoadModelFromMesh(cube);
    this->model.materials[0].shader = LoadShader(TextFormat("bonus/assets/skybox.vs", 330),
                                            TextFormat("bonus/assets/skybox.fs", 330));
    int environmentMap = MATERIAL_MAP_CUBEMAP;
    int doGamma = 0;
    int vflipped = 0;
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "environmentMap"), &environmentMap, SHADER_UNIFORM_INT);
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "doGamma"), &doGamma, SHADER_UNIFORM_INT);
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "vflipped"), &vflipped, SHADER_UNIFORM_INT);
    Image img = LoadImage("bonus/assets/skybox3.png");
    model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(img);
}