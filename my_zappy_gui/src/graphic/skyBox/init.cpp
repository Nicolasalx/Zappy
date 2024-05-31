/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initSkyBox
*/

#include "zappy_gui.hpp"

void Gui::Graphic::init_sky_box()
{
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);
    this->sky_box = LoadModelFromMesh(cube);
    this->sky_box.materials[0].shader = LoadShader(TextFormat("assets/skybox.vs", 330),
                                            TextFormat("assets/skybox.fs", 330));
    int environmentMap = MATERIAL_MAP_CUBEMAP;
    int doGamma = 0;
    int vflipped = 0;
    SetShaderValue(sky_box.materials[0].shader, GetShaderLocation(sky_box.materials[0].shader, "environmentMap"), &environmentMap, SHADER_UNIFORM_INT);
    SetShaderValue(sky_box.materials[0].shader, GetShaderLocation(sky_box.materials[0].shader, "doGamma"), &doGamma, SHADER_UNIFORM_INT);
    SetShaderValue(sky_box.materials[0].shader, GetShaderLocation(sky_box.materials[0].shader, "vflipped"), &vflipped, SHADER_UNIFORM_INT);
    Image img = LoadImage("assets/skybox3.png");
    sky_box.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
    UnloadImage(img);
}
