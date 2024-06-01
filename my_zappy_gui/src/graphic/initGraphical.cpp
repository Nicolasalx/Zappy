/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"
#include "camera.hpp"

Gui::Graphic::Graphic(std::shared_ptr<GameState> gameState)
    : _gameState(gameState), window(), camera(), skyBox(), object(this->_modelList), island(this->_modelList), player(this->_modelList)
{
    this->set_fps(60);
    this->init_lighting();
    this->init_2D();
    this->listLevelPlayer.resize(8);
    this->particle_texture = LoadTexture("assets/evolution.png");
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
