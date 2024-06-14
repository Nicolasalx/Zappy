/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render textbox
*/

#include "zappy_gui.hpp"

static void drawListPlayerLevel(Gui::TextBox_list &textBoxsList)
{
    textBoxsList._textBoxs[3].draw();
    if (textBoxsList._textBoxs[3].isClosed())
        return;
    for (int i = 0; i < 8; ++i) {
        textBoxsList.listLevelPlayer.at(i) = 0;
    }
    for (const auto &player: textBoxsList._gameState->players_list) {
        textBoxsList.listLevelPlayer.at(player.level - 1) += 1;
    }
    for (int i = 0; i < 8; ++i) {
        textBoxsList._textBoxs[3].addText(TextFormat("Level %d: %d", (i + 1), textBoxsList.listLevelPlayer[i]), (i + 0.5f)/8.5f);
    }
}

void Gui::TextBox_list::render(ray_info_t &rayInfo)
{
    _textBoxs[0].draw();
    _textBoxs[0].addText(TextFormat("Number of players: %d", this->_gameState->players_list.size()), 0.5f/2.5f);
    _textBoxs[0].addText(TextFormat("Server frequency: %d", this->_gameState->time_unit), 1.5f/2.5f);
    DrawFPS(10, 10);

    if (rayInfo.type == PLAYER) {
        for (auto &player : this->_gameState->players_list) {
            if (player.n == rayInfo.id) {
                _textBoxs[1].draw();
                _textBoxs[1].addText(TextFormat("Player: %d", player.n), 0.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Level: %d", player.level), 1.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Orientation: %d", player.orientation), 2.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Position: (%.2f, %.2f)", player.real_pos.x, player.real_pos.y), 3.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Inventory:"), 4.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Food: %d", player.inventory[FOOD]), 5.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Linemate: %d", player.inventory[LINEMATE]), 6.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Deraumere: %d", player.inventory[DERAUMERE]), 7.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Sibur: %d", player.inventory[SIBUR]), 8.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Mendiane: %d", player.inventory[MENDIANE]), 9.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Phiras: %d", player.inventory[PHIRAS]), 10.5f/12.5f);
                _textBoxs[1].addText(TextFormat("Thystame: %d", player.inventory[THYSTAME]), 11.5f/12.5f);
            }
        }
    }

    if (rayInfo.type == ISLAND) {
        _textBoxs[2].draw();
        _textBoxs[2].addText(TextFormat("Tile: (%d, %d)"), 0.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Food: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][FOOD]), 1.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Linemate: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][LINEMATE]), 2.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Deraumere: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][DERAUMERE]), 3.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Sibur: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][SIBUR]), 4.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Mendiane: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][MENDIANE]), 5.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Phiras: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][PHIRAS]), 6.5f/8.5f);
        _textBoxs[2].addText(TextFormat("Thystame: %d", this->_gameState->object_pos[rayInfo.y][rayInfo.x][THYSTAME]), 7.5f/8.5f);
    }

    drawListPlayerLevel(*this);

    _textBoxs[4].draw();
    if (_textBoxs[4].isClosed())
        return;
    for (size_t i = 0; i < this->_gameState->server_resp.size(); i++) {
        _textBoxs[4].addText(this->_gameState->server_resp[i], (float)i/(float)this->_gameState->server_resp.size());
    }
}
