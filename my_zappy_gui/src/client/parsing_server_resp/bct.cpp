/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** bct
*/

#include "zappy_gui.hpp"

static bool check_if_already_exist(std::vector<pos_t> object_pos, pos_t pos)
{
    for (size_t i = 0; i < object_pos.size(); i++) {
        if (object_pos[i].x == pos.x && object_pos[i].y == pos.y) {
            return true;
        }
    }
    return false;
}

static void erase_object(std::vector<pos_t> object_pos, pos_t pos)
{
    for (size_t i = 0; i < object_pos.size(); i++) {
        if (object_pos[i].x == pos.x && object_pos[i].y == pos.y) {
            object_pos.erase(object_pos.begin() + i);
        }
    }
}

void GameState::bct(std::vector<std::string> args)
{
    if (args.size() != 9)
        return;
    this->object_pos.clear();
    pos_t pos;
    pos.x = std::stoi(args[0]);
    pos.y = std::stoi(args[1]);
    for (int i = 0; i < 7; i++) {
        if (!check_if_already_exist(this->object_pos[i], pos))
            for (int j = 0; j < std::stoi(args[i + 2]); j++)
                this->object_pos[i].push_back(pos);
        if (std::stoi(args[i + 2]) == 0) {
            erase_object(this->object_pos[i], pos);
        }
    }
}