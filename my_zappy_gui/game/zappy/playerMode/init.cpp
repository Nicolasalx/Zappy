/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** init
*/

#include "PlayerMode.hpp"

void Gui::PlayerMode::addButtonPlayerMode(const std::string &contentText, Pos pos, const SizeButton &sizeButton, std::function<void()> actPlayer)
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
    this->_client->send("Left\n");
    this->_messageQueue->push(Gui::PlayerCmd::LEFT);
}

void Gui::PlayerMode::turnRight()
{
    this->_client->send("Right\n");
    this->_messageQueue->push(Gui::PlayerCmd::RIGHT);
}

void Gui::PlayerMode::forward()
{
    this->_client->send("Forward\n");
    this->_messageQueue->push(Gui::PlayerCmd::FORWARD);
}

void Gui::PlayerMode::look()
{
    this->_client->send("Look\n");
    this->_messageQueue->push(Gui::PlayerCmd::LOOK);
}

void Gui::PlayerMode::eject()
{
    this->_client->send("Eject\n");
    this->_messageQueue->push(Gui::PlayerCmd::EJECT);
}

void Gui::PlayerMode::inventory()
{
    this->_client->send("Inventory\n");
    this->_messageQueue->push(Gui::PlayerCmd::INVENTORY);
}

void Gui::PlayerMode::fork()
{
    this->_client->send("Fork\n");
    this->_messageQueue->push(Gui::PlayerCmd::FORK);
}

void Gui::PlayerMode::incantation()
{
    this->_client->send("Incantation\n");
    this->_messageQueue->push(Gui::PlayerCmd::INCANTATION);
}

std::string Gui::PlayerMode::getNameElementFromEnum(Elements elements)
{
    std::string nameElement;

    switch (elements) {
        case FOOD:
            nameElement += "food\n";
            break;
        case LINEMATE:
            nameElement += "linemate\n";
            break;
        case DERAUMERE:
            nameElement += "deraumere\n";
            break;
        case SIBUR:
            nameElement += "sibur\n";
            break;
        case MENDIANE:
            nameElement += "mendiane\n";
            break;
        case PHIRAS:
            nameElement += "phiras\n";
            break;
        case THYSTAME:
            nameElement += "thystame\n";
            break;
        default:
            break;
    }
    return nameElement;
}

void Gui::PlayerMode::takeElement(Elements elements)
{
    std::string cmdToSend = "Take ";
    
    cmdToSend += getNameElementFromEnum(elements);
    this->_client->send(cmdToSend);
    this->_messageQueue->push(Gui::PlayerCmd::TAKE);
}

void Gui::PlayerMode::setElement(Elements elements)
{
    std::string cmdToSend = "Set ";
    
    cmdToSend += getNameElementFromEnum(elements);
    this->_client->send(cmdToSend);
    this->_messageQueue->push(Gui::PlayerCmd::SET);
}

void Gui::PlayerMode::initButtonPlayerMode()
{
    Pos pos = {0.2, 0.88};

    addButtonPlayerMode("LEFT", pos, MIDDLE, [this]() {this->turnLeft();});
    addButtonPlayerMode("FORWARD", {pos.x + 0.035f, pos.y - 0.11f}, MIDDLE, [this]() {this->forward();});
    addButtonPlayerMode("RIGHT", {pos.x + 0.07f, pos.y}, MIDDLE, [this]() {this->turnRight();});

    addButtonPlayerMode("LOOK", {pos.x + 0.15f, pos.y - 0.11f}, MIDDLE, [this]() {this->look();});
    addButtonPlayerMode("EJECT", {pos.x + 0.22f, pos.y - 0.11f}, MIDDLE, [this]() {this->eject();});
    addButtonPlayerMode("INVENTORY", {pos.x + 0.15f, pos.y}, MIDDLE, [this]() {this->inventory();});
    addButtonPlayerMode("FORK", {pos.x + 0.22f, pos.y}, MIDDLE, [this]() {this->fork();});
    addButtonPlayerMode("INCANTATION", {pos.x + 0.29f, pos.y}, MIDDLE, [this]() {this->incantation();});

    addButtonPlayerMode("TAKE OBJECT", {pos.x + 0.38f, pos.y - 0.11f}, BIG, nullptr);
    addButtonPlayerMode("FOOD", {pos.x + 0.385f, pos.y - 0.10f}, LITTLE, [this]() {this->takeElement(FOOD);});
    addButtonPlayerMode("LINEMATE", {pos.x + 0.44f, pos.y - 0.10f}, LITTLE, [this]() {this->takeElement(LINEMATE);});
    addButtonPlayerMode("DERAUMERE", {pos.x + 0.49f, pos.y - 0.10f}, LITTLE, [this]() {this->takeElement(DERAUMERE);});
    addButtonPlayerMode("SIBUR", {pos.x + 0.385f, pos.y}, LITTLE, [this]() {this->takeElement(SIBUR);});
    addButtonPlayerMode("MENDIANE", {pos.x + 0.425f, pos.y}, LITTLE, [this]() {this->takeElement(MENDIANE);});
    addButtonPlayerMode("PHIRAS", {pos.x + 0.465f, pos.y}, LITTLE, [this]() {this->takeElement(PHIRAS);});
    addButtonPlayerMode("THYSTAME", {pos.x + 0.505f, pos.y}, LITTLE, [this]() {this->takeElement(THYSTAME);});

    addButtonPlayerMode("SET OBJECT", {pos.x + 0.58f, pos.y - 0.11f}, BIG, nullptr);
    addButtonPlayerMode("FOOD", {pos.x + 0.585f, pos.y - 0.10f}, LITTLE, [this]() {this->setElement(FOOD);});
    addButtonPlayerMode("LINEMATE", {pos.x + 0.64f, pos.y - 0.10f}, LITTLE, [this]() {this->setElement(LINEMATE);});
    addButtonPlayerMode("DERAUMERE", {pos.x + 0.69f, pos.y - 0.10f}, LITTLE, [this]() {this->setElement(DERAUMERE);});
    addButtonPlayerMode("SIBUR", {pos.x + 0.585f, pos.y}, LITTLE, [this]() {this->setElement(SIBUR);});
    addButtonPlayerMode("MENDIANE", {pos.x + 0.625f, pos.y}, LITTLE, [this]() {this->setElement(MENDIANE);});
    addButtonPlayerMode("PHIRAS", {pos.x + 0.665f, pos.y}, LITTLE, [this]() {this->setElement(PHIRAS);});
    addButtonPlayerMode("THYSTAME", {pos.x + 0.705f, pos.y}, LITTLE, [this]() {this->setElement(THYSTAME);});
}

void Gui::PlayerMode::setSendedMessageQueue(std::shared_ptr<std::queue<Gui::PlayerCmd>> messageQueue)
{
    if (!_hasBeenUpdatedMessQueue) {
        this->_messageQueue = messageQueue;
        this->_hasBeenUpdatedMessQueue = true;
    }
}

Gui::PlayerMode::PlayerMode(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client) : _gameData(gameData), _client(client)
{
    initButtonPlayerMode();
}
