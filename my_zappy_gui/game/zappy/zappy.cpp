/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Zappy.hpp"

Gui::Zappy::Zappy(std::shared_ptr<Gui::IClient> client, std::shared_ptr<Gui::GameData> gameData): _client(client),
    island(std::make_unique<Gui::Island>(gameData)), object(std::make_unique<Gui::Object>(gameData)), particle(std::make_unique<Gui::Particle>(gameData)),
    player(std::make_unique<Gui::Player>(gameData))
{

}

Gui::Zappy::~Zappy()
{

}
