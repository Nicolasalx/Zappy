/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_2d
*/

#include "zappy_gui.hpp"

void Gui::Graphic::draw_general_info()
{
    textBoxs[0].draw();
    textBoxs[0].add_text(TextFormat("Number of players: %d", this->_gameState->players_list.size()), 0.5f/2.5f);
    textBoxs[0].add_text(TextFormat("Server frequency: %d", this->_gameState->time_unit), 1.5f/2.5f);
    DrawFPS(10, 10);
}

void Gui::Graphic::draw_tile_info()
{
    if (this->rayInfo.type == ISLAND) {
        textBoxs[2].draw();
        textBoxs[2].add_text(TextFormat("Tile: (%d, %d)"), 0.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Food: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][FOOD]), 1.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Linemate: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][LINEMATE]), 2.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Deraumere: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][DERAUMERE]), 3.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Sibur: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][SIBUR]), 4.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Mendiane: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][MENDIANE]), 5.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Phiras: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][PHIRAS]), 6.5f/8.5f);
        textBoxs[2].add_text(TextFormat("Thystame: %d", this->_gameState->object_pos[this->rayInfo.y][this->rayInfo.x][THYSTAME]), 7.5f/8.5f);
    }
}
