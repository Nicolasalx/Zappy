/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Raylib.hpp"
#include "Window.hpp"

Gui::Window::Window()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    this->window_width = GetScreenWidth();
    this->window_height = GetScreenHeight();
}

Gui::Window::~Window()
{
    CloseWindow();
}