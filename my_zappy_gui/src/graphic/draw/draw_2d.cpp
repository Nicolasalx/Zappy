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
                textBoxs[1].add_text(TextFormat("Player: %d", player.n), 0.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Level: %d", player.level), 1.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Orientation: %d", player.orientation), 2.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Position: (%.2f, %.2f)", player.real_pos.x, player.real_pos.y), 3.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Inventory:"), 4.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Food: %d", player.inventory[FOOD]), 5.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Linemate: %d", player.inventory[LINEMATE]), 6.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Deraumere: %d", player.inventory[DERAUMERE]), 7.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Sibur: %d", player.inventory[SIBUR]), 8.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Mendiane: %d", player.inventory[MENDIANE]), 9.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Phiras: %d", player.inventory[PHIRAS]), 10.5f/12.5f);
                textBoxs[1].add_text(TextFormat("Thystame: %d", player.inventory[THYSTAME]), 11.5f/12.5f);
            }
        }
    }
}

void Graphic::draw_all_player_level()
{
    double multiplicator = 0.08;

    this->listLevelPlayer.resize(8);
    for (int i = 0; i < 8; ++i) {
        this->listLevelPlayer.at(i) = 0;
    }
    for (const auto &player: this->gameState->players_list) {
        this->listLevelPlayer.at(player.level - 1) += 1;
    }
    textBoxs[3].draw();
    for (int i = 0; i < 8; ++i) {
        int newInt = 0;
        if (this->listLevelPlayer.size() == 8) {
            newInt = this->listLevelPlayer.at(i);
        }
        textBoxs[3].add_text(TextFormat("Level %d: %d", (i + 1), newInt), (i + 0.5f)/8.5f);
    }
}

void Graphic::draw_tile_info()
{
    if (this->rayInfo.type == ISLAND) {
        textBoxs[2].draw();
        textBoxs[2].add_text(TextFormat("Tile: (%d, %d)"), 0.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Food: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][FOOD]), 1.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Linemate: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][LINEMATE]), 2.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Deraumere: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][DERAUMERE]), 3.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Sibur: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][SIBUR]), 4.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Mendiane: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][MENDIANE]), 5.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Phiras: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][PHIRAS]), 6.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Thystame: %d", this->gameState->object_pos[this->rayInfo.y][this->rayInfo.x][THYSTAME]), 7.5f/8.5f);
    }
}