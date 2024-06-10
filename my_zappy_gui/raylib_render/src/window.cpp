/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Raylib.hpp"
#include "RenderWindow.hpp"

Gui::SizeWindow Gui::RenderWindow::sizeWindow = { WINDOW_WIDTH, WINDOW_HEIGHT };

Gui::RenderWindow::RenderWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    sizeWindow.width = GetScreenWidth();
    sizeWindow.height = GetScreenHeight();
}

Gui::RenderWindow::~RenderWindow()
{
    CloseWindow();
}
