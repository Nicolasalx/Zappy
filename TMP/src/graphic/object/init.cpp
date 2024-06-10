/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "object.hpp"

Gui::Object::Object(std::shared_ptr<Gui::GameState> gameState): _gameState(gameState)
{
    this->addModel("bonus/assets/food.glb", "bonus/assets/texture_food.png");
    this->addModel("bonus/assets/linemate.obj", "bonus/assets/texture_linemate.png");
    this->addModel("bonus/assets/deraumere.obj", "bonus/assets/texture_deraumere.png");
    this->addModel("bonus/assets/sibur.obj", "bonus/assets/texture_sibur.png");
    this->addModel("bonus/assets/mendiane.obj", "bonus/assets/texture_mendiane.png");
    this->addModel("bonus/assets/phiras.obj", "bonus/assets/texture_phiras.png");
    this->addModel("bonus/assets/thystame.obj", "bonus/assets/texture_thystame.png");

    for (int i = 0; i < 7; i++) {
        this->object_padding[i][0] = std::cos((std::numbers::pi / 180.0) * (i * 50.0));
        this->object_padding[i][1] = std::sin((std::numbers::pi / 180.0) * (i * 50.0));
    }
}