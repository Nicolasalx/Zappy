/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

Graphic::Graphic(GameState *gameState)
{
    this->gameState = gameState;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    this->init_camera();
    this->set_fps(60);
    this->init_sky_box();
    this->init_object();
    this->init_island();
    this->init_player();
    this->init_object_padding();
}

Graphic::~Graphic()
{
    CloseWindow();
}

void Graphic::init_camera()
{
    this->camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    this->camera.fovy = 90.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
    DisableCursor();
}

void Graphic::set_fps(int fps)
{
    SetTargetFPS(fps);
}

void Graphic::init_sky_box()
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

void Graphic::init_island()
{
    //avec un cube pour l'instant
    Mesh cube = GenMeshCube(3.0f, 3.0f, 3.0f);
    Model island = LoadModelFromMesh(cube);
    this->model_list.push_back(island);
}

void Graphic::init_player()
{
    Model player = LoadModel("assets/model.iqm");
    Texture2D texture = LoadTexture("assets/test_texture.png");
    SetMaterialTexture(&player.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    player.transform = MatrixRotateXYZ((Vector3){-90.0f * (PI / 180), 0.0f, 0.0f});
    this->model_list.push_back(player);

    int animsCount = 1;
    this->player_animation = LoadModelAnimations("assets/model.iqm", &animsCount);
}

void Graphic::init_object()
{
    // food
    Mesh sphere = GenMeshSphere(0.5f, 32, 32);
    Model food = LoadModelFromMesh(sphere);
    this->model_list.push_back(food);
    // limenate
    Mesh limenate = GenMeshCylinder(0.5f, 1.0f, 32);
    Model limenate_model = LoadModelFromMesh(limenate);
    this->model_list.push_back(limenate_model);
    // deraumere
    Mesh deraumere = GenMeshCone(0.5f, 1.0f, 32);
    Model deraumere_model = LoadModelFromMesh(deraumere);
    this->model_list.push_back(deraumere_model);
    // sibur
    Mesh sibur = GenMeshTorus(0.5f, 1.0f, 32, 32);
    Model sibur_model = LoadModelFromMesh(sibur);
    this->model_list.push_back(sibur_model);
    // mendiane
    Mesh mendiane = GenMeshCube(0.5f, 1.0f, 1.0f);
    Model mendiane_model = LoadModelFromMesh(mendiane);
    this->model_list.push_back(mendiane_model);
    // phiras
    Mesh phiras = GenMeshCylinder(0.5f, 1.0f, 32);
    Model phiras_model = LoadModelFromMesh(phiras);
    this->model_list.push_back(phiras_model);
    // thystame
    Mesh thystame = GenMeshCylinder(0.5f, 1.0f, 32);
    Model thystame_model = LoadModelFromMesh(thystame);
    this->model_list.push_back(thystame_model);
}

void Graphic::init_object_padding()
{
    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = cos((PI / 180.0f) * (i * 50.0f));
        this->object_padding[i][1] = sin((PI / 180.0f) * (i * 50.0f));
    }
}