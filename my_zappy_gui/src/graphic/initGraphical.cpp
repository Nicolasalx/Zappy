/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init_all
*/

#include "zappy_gui.hpp"
#include "camera.hpp"

Gui::Graphic::Graphic(GameState *gameState): window(), camera()
{
    this->gameState = gameState;

    this->set_fps(60);
    this->init_sky_box();
    this->init_object();
    this->init_island();
    this->init_player();
    this->init_object_padding();
    this->init_lighting();
    this->init_2D();
    this->player_orientation[1] = 180;
    this->player_orientation[2] = 90;
    this->player_orientation[3] = 0;
    this->player_orientation[4] = 270;
    this->listLevelPlayer.resize(8);
    this->particle_texture = LoadTexture("assets/plateform1.png");
}

Gui::Graphic::~Graphic()
{
    CloseWindow();
}

void Gui::Graphic::init_2D()
{
    this->textBoxs.push_back(TextBox(0.77f, 0.04f, 0.21f, 0.1f, this->window.window_width, this->window.window_height, LEFT_BUTTON));
    this->textBoxs.push_back(TextBox(0.77f, 0.47f, 0.21f, 0.51f, this->window.window_width, this->window.window_height));
    this->textBoxs.push_back(TextBox(0.77f, 0.47f, 0.21f, 0.40f, this->window.window_width, this->window.window_height));
    this->textBoxs.push_back(TextBox(0.01f, 0.57f, 0.15f, 0.40f, this->window.window_width, this->window.window_height, RIGHT_BUTTON));
}

Gui::Window::Window()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    this->window_width = GetScreenWidth();
    this->window_height = GetScreenHeight();
}

void Gui::Graphic::set_fps(int fps)
{
    SetTargetFPS(fps);
}

void Gui::Graphic::init_lighting()
{
    // light_shader = LoadShader(TextFormat("assets/lighting.vs", 330),
    //                            TextFormat("assets/lighting.fs", 330));
    // light_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(light_shader, "viewPos");
    // float test[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    // int ambientLoc = GetShaderLocation(light_shader, "ambient");
    // SetShaderValue(light_shader, ambientLoc, test, SHADER_UNIFORM_VEC4);
}
