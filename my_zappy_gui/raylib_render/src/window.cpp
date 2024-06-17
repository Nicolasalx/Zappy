/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Raylib.hpp"
#include "RenderWindow.hpp"

Gui::RenderWindow::RenderWindow()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Zappy GUI");
    windowSize.width = GetScreenWidth();
    windowSize.height = GetScreenHeight();
    launched = false;
    InitAudioDevice();
    this->_soundGame = LoadSound(Gui::SOUND_GAME.data());
    PlaySound(this->_soundGame);
}

Gui::RenderWindow::~RenderWindow()
{
    UnloadSound(this->_soundGame);
    CloseAudioDevice();
    CloseWindow();
}
