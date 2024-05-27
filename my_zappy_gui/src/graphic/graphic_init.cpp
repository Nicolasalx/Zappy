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
    this->init_lighting();
    this->player_orientation[1] = 180;
    this->player_orientation[2] = 90;
    this->player_orientation[3] = 0;
    this->player_orientation[4] = 270;
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
    
    Model island = LoadModel("assets/plateform.obj");
    Texture2D texture = LoadTexture("assets/plateform1.png");
    SetTextureFilter(texture, TEXTURE_FILTER_TRILINEAR);
    SetMaterialTexture(&island.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    this->model_list.push_back(island);
}

void Graphic::init_player()
{
    Model player = LoadModel("assets/Astronaut.iqm");
    Texture2D texture = LoadTexture("assets/AstronautColor.png");
    SetMaterialTexture(&player.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    player.transform = MatrixRotateXYZ((Vector3){-90.0f * (PI / 180), 0.0f, 0.0f});
    this->model_list.push_back(player);

    int animsCount = 5;
    this->player_animation = LoadModelAnimations("assets/Astronaut.iqm", &animsCount);
}

void Graphic::init_object()
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
    // Texture2D texture_p = LoadTexture("assets/texture_phiras.png");
    // SetMaterialTexture(&phiras_model.materials[0], MATERIAL_MAP_DIFFUSE, texture_p);
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

void Graphic::init_lighting()
{
    // light_shader = LoadShader(TextFormat("assets/lighting.vs", 330),
    //                            TextFormat("assets/lighting.fs", 330));
    // light_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(light_shader, "viewPos");
    // float test[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    // int ambientLoc = GetShaderLocation(light_shader, "ambient");
    // SetShaderValue(light_shader, ambientLoc, test, SHADER_UNIFORM_VEC4);
}
