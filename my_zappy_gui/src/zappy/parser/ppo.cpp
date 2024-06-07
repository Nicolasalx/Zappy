/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ppo
*/

#include "Parser.hpp"

void Gui::Parser::ppo(std::vector<std::string> args)
{
    if (args.size() != 4)
        return;
    int playerId = std::stoi(args[0]);
    for (auto it = _gameData->playerList.begin(); it != _gameData->playerList.end(); it++) {
        if (it->n == playerId) {
            it->pos.x = std::stoi(args[1]);
            it->pos.y = std::stoi(args[2]);
            it->orientation = std::stoi(args[3]);
            it->animation_nbr = 0;
            it->anim_frame_counter = 152;
            break;
        }
    }
}
