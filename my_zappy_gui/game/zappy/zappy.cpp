/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy
*/

#include "Zappy.hpp"

Gui::Zappy::Zappy(const std::shared_ptr<Gui::IClient>& client,
    const std::shared_ptr<Gui::GameData>& gameData)
    : _client(client), _parser(gameData), _playerParser(gameData),
    _island(gameData), _object(gameData),
    _player(gameData), _egg(gameData),
    _textBox(gameData, client), _menu(gameData), _playerMode(gameData, client)
{
    this->_gameData = gameData;
}
