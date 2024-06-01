/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** renderPlayer
*/

#include "zappy_gui.hpp"

void Gui::Graphic::drawPlayerInfo()
{
    if (this->rayInfo.type == PLAYER) {
        for (auto &player : this->_gameState->players_list) {
            if (player.n == this->rayInfo.id) {
                textBoxs[1].draw();
                textBoxs[1].addText(TextFormat("Player: %d", player.n), 0.5f/12.5f);
                textBoxs[1].addText(TextFormat("Level: %d", player.level), 1.5f/12.5f);
                textBoxs[1].addText(TextFormat("Orientation: %d", player.orientation), 2.5f/12.5f);
                textBoxs[1].addText(TextFormat("Position: (%.2f, %.2f)", player.real_pos.x, player.real_pos.y), 3.5f/12.5f);
                textBoxs[1].addText(TextFormat("Inventory:"), 4.5f/12.5f);
                textBoxs[1].addText(TextFormat("Food: %d", player.inventory[FOOD]), 5.5f/12.5f);
                textBoxs[1].addText(TextFormat("Linemate: %d", player.inventory[LINEMATE]), 6.5f/12.5f);
                textBoxs[1].addText(TextFormat("Deraumere: %d", player.inventory[DERAUMERE]), 7.5f/12.5f);
                textBoxs[1].addText(TextFormat("Sibur: %d", player.inventory[SIBUR]), 8.5f/12.5f);
                textBoxs[1].addText(TextFormat("Mendiane: %d", player.inventory[MENDIANE]), 9.5f/12.5f);
                textBoxs[1].addText(TextFormat("Phiras: %d", player.inventory[PHIRAS]), 10.5f/12.5f);
                textBoxs[1].addText(TextFormat("Thystame: %d", player.inventory[THYSTAME]), 11.5f/12.5f);
            }
        }
    }
}

void Gui::Graphic::drawAllPlayerLevel()
{
    textBoxs[3].draw();
    if (textBoxs[3].isClosed())
        return;
    for (int i = 0; i < 8; ++i) {
        this->listLevelPlayer.at(i) = 0;
    }
    for (const auto &player: this->_gameState->players_list) {
        this->listLevelPlayer.at(player.level - 1) += 1;
    }
    for (int i = 0; i < 8; ++i) {
        textBoxs[3].addText(TextFormat("Level %d: %d", (i + 1), listLevelPlayer[i]), (i + 0.5f)/8.5f);
    }
}