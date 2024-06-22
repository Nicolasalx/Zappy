/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initObject
*/

#include "Object.hpp"

Gui::Object::Object(std::shared_ptr<Gui::GameData> gameData) : _gameData(std::move(gameData))
{
}
