/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "PlayerMode.hpp"

void Gui::PlayerMode::addButtonPlayerMode(const std::string &contentText, Pos pos, const SizeButton &sizeButton, ActionButtonPlayer actPlayer)
{
    ButtonPlayerMode buttonPlayerMode;
    Size size;
    Pos posText;

    if (sizeButton == BIG) {
        size = { 0.18, 0.21 };
        posText = {pos.x + 0.05f, pos.y - 0.03f };
    } else if (sizeButton == MIDDLE) {
        size = {0.06, 0.1};
        posText = pos;
    } else {
        posText = pos;
        size = {0.035, 0.06};
    }
    buttonPlayerMode.button = {.pos = pos, .size = size, .realPos = pos, .realSize = size, .color = WHITE_COLOR};
    buttonPlayerMode.text = {.contentText = contentText, .pos = posText, .realPos = posText, .fontSize = 15, .color = BLACK_COLOR};
    buttonPlayerMode.actPlayer = actPlayer;
    this->_gameData->playerMode.buttonPlayerMode.push_back(buttonPlayerMode);
}

void Gui::PlayerMode::turnLeft()
{
    std::cout << "TURN LEFT\n";
}

// void Gui::PlayerMode::initButtonPlayerMode()
// {
//     Pos pos = {0.2, 0.88};

//     addButtonPlayerMode("LEFT", pos, MIDDLE, std::bind(&PlayerMode:turnLeft, this));
//     addButtonPlayerMode("FORWARD", {pos.x + 0.035f, pos.y - 0.11f}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("RIGHT", {pos.x + 0.07f, pos.y}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));

//     addButtonPlayerMode("LOOK", {pos.x + 0.15f, pos.y - 0.11f}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("EJECT", {pos.x + 0.22f, pos.y - 0.11f}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("INVENTORY", {pos.x + 0.15f, pos.y}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("FORK", {pos.x + 0.22f, pos.y}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("INCANTATION", {pos.x + 0.29f, pos.y}, MIDDLE, std::bind(&PlayerMode::turnLeft, this));

//     addButtonPlayerMode("TAKE OBJECT", {pos.x + 0.38f, pos.y - 0.11f}, BIG, NULL);
//     addButtonPlayerMode("1", {pos.x + 0.385f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("2", {pos.x + 0.44f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("3", {pos.x + 0.49f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("4", {pos.x + 0.385f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("5", {pos.x + 0.425f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("6", {pos.x + 0.465f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("7", {pos.x + 0.505f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));

//     addButtonPlayerMode("SET OBJECT", {pos.x + 0.58f, pos.y - 0.11f}, BIG, NULL);
//     addButtonPlayerMode("1", {pos.x + 0.585f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("2", {pos.x + 0.64f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("3", {pos.x + 0.69f, pos.y - 0.10f}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("4", {pos.x + 0.585f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("5", {pos.x + 0.625f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("6", {pos.x + 0.665f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
//     addButtonPlayerMode("7", {pos.x + 0.705f, pos.y}, LITTLE, std::bind(&PlayerMode::turnLeft, this));
// }

Gui::PlayerMode::PlayerMode(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client) : _gameData(gameData), _client(client)
{
    initButtonPlayerMode();
}
