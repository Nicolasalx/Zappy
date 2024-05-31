/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** renderPlayer
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_player_info()
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

void Gui::Graphic::draw_all_player_level()
{
    textBoxs[3].draw();
    if (textBoxs[3].is_closed())
        return;
    for (int i = 0; i < 8; ++i) {
        this->listLevelPlayer.at(i) = 0;
    }
    for (const auto &player: this->gameState->players_list) {
        this->listLevelPlayer.at(player.level - 1) += 1;
    }
    for (int i = 0; i < 8; ++i) {
        textBoxs[3].add_text(TextFormat("Level %d: %d", (i + 1), listLevelPlayer[i]), (i + 0.5f)/8.5f);
    }
}