/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "object.hpp"

Gui::Object::Object(std::shared_ptr<Gui::GameState> gameState): _gameState(gameState)
{
    this->addModel("assets/food.glb", "assets/texture_food.png");
    this->addModel("assets/linemate.obj", "assets/texture_linemate.png");
    this->addModel("assets/deraumere.obj", "assets/texture_deraumere.png");
    this->addModel("assets/sibur.obj", "assets/texture_sibur.png");
    this->addModel("assets/mendiane.obj", "assets/texture_mendiane.png");
    this->addModel("assets/phiras.obj", "assets/texture_phiras.png");
    this->addModel("assets/thystame.obj", "assets/texture_thystame.png");

    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = cos((PI / 180.0f) * (i * 50.0f));
        this->object_padding[i][1] = sin((PI / 180.0f) * (i * 50.0f));
    }
}
