/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "RenderSkyBox.hpp"
#include "GameConfig.hpp"

Gui::RenderSkyBox::RenderSkyBox()
{
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
    this->model = LoadModelFromMesh(cube);
    this->model.materials[0].shader = LoadShader(TextFormat(SKYBOX_VERTEX_SHADER.data(), 330),
                                            TextFormat(SKYBOX_FRAGMENT_SHADER.data(), 330));
    int environmentMap = MATERIAL_MAP_CUBEMAP;
    int doGamma = 0;
    int vflipped = 0;
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "environmentMap"), &environmentMap, SHADER_UNIFORM_INT);
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "doGamma"), &doGamma, SHADER_UNIFORM_INT);
    SetShaderValue(model.materials[0].shader, GetShaderLocation(model.materials[0].shader, "vflipped"), &vflipped, SHADER_UNIFORM_INT);
    Image img = LoadImage(SKYBOX_TEXTURE.data());
    model.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(img);
}

Gui::RenderSkyBox::~RenderSkyBox()
{
    UnloadModel(this->model);
}

void Gui::RenderSkyBox::render()
{
    ClearBackground(RAYWHITE);
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
        DrawModel(model, (Vector3){0, 0, 0}, 1.0f, WHITE);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}
