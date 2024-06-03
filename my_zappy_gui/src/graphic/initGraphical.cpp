/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"
#include "camera.hpp"

Gui::Graphic::Graphic(std::shared_ptr<GameState> gameState)
    : _gameState(gameState), window(), camera(), skyBox(gameState), object(gameState), island(gameState), player(gameState), menu(gameState), particle(gameState), textBoxs(gameState, window.window_width, window.window_height)
{
    this->setFps(60);
    this->initLighting();
    this->loop();
}

Gui::Graphic::~Graphic()
{
    CloseWindow();
}

Gui::Window::Window()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    this->window_width = GetScreenWidth();
    this->window_height = GetScreenHeight();
}

void Gui::Graphic::setFps(int fps)
{
    SetTargetFPS(fps);
}

void Gui::Graphic::initLighting()
{
    // light_shader = LoadShader(TextFormat("assets/lighting.vs", 330),
    //                            TextFormat("assets/lighting.fs", 330));
    // light_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(light_shader, "viewPos");
    // float test[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    // int ambientLoc = GetShaderLocation(light_shader, "ambient");
    // SetShaderValue(light_shader, ambientLoc, test, SHADER_UNIFORM_VEC4);
}
