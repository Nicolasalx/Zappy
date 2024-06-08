/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Zappy.hpp"

Gui::Zappy::Zappy(std::shared_ptr<Gui::IClient> client, std::shared_ptr<Gui::GameData> gameData): _client(client), island(gameData)
{

}

Gui::Zappy::~Zappy()
{

}
