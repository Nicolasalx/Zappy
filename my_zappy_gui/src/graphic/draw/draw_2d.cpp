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

void Graphic::draw_player_info()
{
    if (this->rayInfo.type == PLAYER) {
        for (auto &player : this->gameState->players_list) {
            if (player.n == this->rayInfo.id) {
                DrawRectangleRec(textBoxs[1], CLITERAL(Color){200, 200, 255, 100});
                DrawRectangleLines(window_width * 0.76f, window_height / 3.0f, window_width / 4.5f, window_height * 0.75, WHITE);
                DrawText(TextFormat("Player: %d", player.n), window_width * 0.80, window_height * 0.5, window_width / 60, WHITE);
                DrawText(TextFormat("Level: %d", player.level), window_width * 0.80, window_height * 0.54, window_width / 60, WHITE);
                DrawText(TextFormat("Orientation: %d", player.orientation), window_width * 0.80, window_height * 0.58, window_width / 60, WHITE);
                DrawText(TextFormat("Position: (%.2f, %.2f)", player.real_pos.x, player.real_pos.y), window_width * 0.80, window_height * 0.62, window_width / 60, WHITE);
                DrawText(TextFormat("Inventory:"), window_width * 0.80, window_height * 0.66, window_width / 60, WHITE);
                DrawText(TextFormat("Food: %d", player.inventory[FOOD]), window_width * 0.80, window_height * 0.70, window_width / 60, WHITE);
                DrawText(TextFormat("Linemate: %d", player.inventory[LINEMATE]), window_width * 0.80, window_height * 0.74, window_width / 60, WHITE);
                DrawText(TextFormat("Deraumere: %d", player.inventory[DERAUMERE]), window_width * 0.80, window_height * 0.78, window_width / 60, WHITE);
                DrawText(TextFormat("Sibur: %d", player.inventory[SIBUR]), window_width * 0.80, window_height * 0.82, window_width / 60, WHITE);
                DrawText(TextFormat("Mendiane: %d", player.inventory[MENDIANE]), window_width * 0.80, window_height * 0.86, window_width / 60, WHITE);
                DrawText(TextFormat("Phiras: %d", player.inventory[PHIRAS]), window_width * 0.80, window_height * 0.90, window_width / 60, WHITE);
                DrawText(TextFormat("Thystame: %d", player.inventory[THYSTAME]), window_width * 0.80, window_height * 0.94, window_width / 60, WHITE);
            }
        }
    }
}