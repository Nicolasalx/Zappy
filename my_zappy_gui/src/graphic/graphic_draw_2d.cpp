/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_2d
*/

#include "zappy_gui.hpp"

void Graphic::draw_general_info()
{
    DrawRectangleRec(textBoxs[0], CLITERAL(Color){200, 200, 255, 100});
    DrawRectangleLines(window_width * 0.76f, window_height / 21.0f, window_width / 4.5f, window_height / 10.0f, WHITE);
    DrawText(TextFormat("Number of players: %d", this->gameState->players_list.size()), window_width * 0.77, window_height / 20, window_width / 60, WHITE);
    DrawText(TextFormat("Server frequency: %d", this->gameState->time_unit), window_width * 0.77, window_height / 10, window_width / 60, WHITE);
    DrawFPS(10, 10);
}