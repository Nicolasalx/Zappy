/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_2d
*/

#include "zappy_gui.hpp"

void Graphic::draw_general_info()
{
    textBoxs[0].draw();
    DrawText(TextFormat("Number of players: %d", this->gameState->players_list.size()), window_width * 0.79, window_height / 20, window_width / 60, WHITE);
    DrawText(TextFormat("Server frequency: %d", this->gameState->time_unit), window_width * 0.79, window_height / 10, window_width / 60, WHITE);
    DrawFPS(10, 10);
}

void Graphic::draw_player_info()
{
    if (this->rayInfo.type == PLAYER) {
        for (auto &player : this->gameState->players_list) {
            if (player.n == this->rayInfo.id) {
                textBoxs[1].draw();
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

void Graphic::draw_tile_info()
{
    if (this->rayInfo.type == ISLAND) {
        textBoxs[2].draw();
        DrawText(TextFormat("Tile: (%d, %d)", this->rayInfo.x, this->rayInfo.y), window_width * 0.80, window_height * 0.5, window_width / 60, WHITE);
        DrawText(TextFormat("Food: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][FOOD]), window_width * 0.80, window_height * 0.54, window_width / 60, WHITE);
        DrawText(TextFormat("Linemate: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][LINEMATE]), window_width * 0.80, window_height * 0.58, window_width / 60, WHITE);
        DrawText(TextFormat("Deraumere: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][DERAUMERE]), window_width * 0.80, window_height * 0.62, window_width / 60, WHITE);
        DrawText(TextFormat("Sibur: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][SIBUR]), window_width * 0.80, window_height * 0.66, window_width / 60, WHITE);
        DrawText(TextFormat("Mendiane: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][MENDIANE]), window_width * 0.80, window_height * 0.70, window_width / 60, WHITE);
        DrawText(TextFormat("Phiras: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][PHIRAS]), window_width * 0.80, window_height * 0.74, window_width / 60, WHITE);
        DrawText(TextFormat("Thystame: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][THYSTAME]), window_width * 0.80, window_height * 0.78, window_width / 60, WHITE);
    }
}