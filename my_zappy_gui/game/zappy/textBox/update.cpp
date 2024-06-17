/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateTextBox
*/

#include "TextBox.hpp"

void Gui::TextBox::addText(TextBoxData &textBox, size_t index, std::string text)
{
    if (textBox._text.size() <= index) {
        textBox._text.push_back(text);
    } else {
        textBox._text.at(index) = text;
    }
}

bool Gui::TextBox::isClosed(TextBoxData &_text)
{
    if (_text._state == CLOSED_RIGHT || _text._state == CLOSED_LEFT)
        return true;
    return false;
}

void Gui::TextBox::openClose(const Gui::Event &event)
{
    for (auto &_button : _gameData->textBox) {
        if (event.mouse.x > _button._buttonPos.x && event.mouse.x < _button._buttonPos.x + _button._buttonSize.x &&
            event.mouse.y > _button._buttonPos.y && event.mouse.y < _button._buttonPos.y + _button._buttonSize.y) {
            if (_button._state == RIGHT_BUTTON) {
                _button._state = CLOSED_RIGHT;
                resize(_gameData->windowX, _gameData->windowY);
            }
            else if (_button._state == LEFT_BUTTON) {
                _button._state = CLOSED_LEFT;
                resize(_gameData->windowX, _gameData->windowY);
            }
            else if (_button._state == CLOSED_RIGHT) {
                _button._state = RIGHT_BUTTON;
                resize(_gameData->windowX, _gameData->windowY);
            }
            else if (_button._state == CLOSED_LEFT) {
                _button._state = LEFT_BUTTON;
                resize(_gameData->windowX, _gameData->windowY);
            }
        }
    }
}

void Gui::TextBox::updateListPlayerLevel()
{
    if (_gameData->textBox.size() < 4 || isClosed(_gameData->textBox[0]))
        return;
    for (int i = 0; i < 8; ++i) {
        listLevelPlayer.at(i) = 0;
    }
    for (const auto &player: _gameData->playerList) {
        listLevelPlayer.at(player.level - 1) += 1;
    }
    for (int i = 0; i < 8; ++i) {
        addText(_gameData->textBox[3], i, "Level " + std::to_string(i + 1) + ": " + std::to_string(listLevelPlayer[i]));
    }
}

void Gui::TextBox::updateGeneralInfo()
{
    if (_gameData->textBox.size() < 1 || isClosed(_gameData->textBox[0]))
        return;
    addText(_gameData->textBox[0], 0, "Number of players: " + std::to_string(_gameData->playerList.size()));
    addText(_gameData->textBox[0], 1, "Server frequency: " + std::to_string(_gameData->timeUnit));
    addText(_gameData->textBox[0], 2, "");
    addText(_gameData->textBox[0], 3, "Map size: " + std::to_string((int)_gameData->mapSize.x) + "x" + std::to_string((int)_gameData->mapSize.y));
}

void Gui::TextBox::updateServerResp()
{
    if (_gameData->textBox.size() < 5 || isClosed(_gameData->textBox[0]))
        return;
    for (size_t i = 0; i < this->_gameData->serverResp.size(); i++) {
        addText(_gameData->textBox[4], i, _gameData->serverResp[i]);
    }
}

void Gui::TextBox::updateBroadcastResp()
{
    if (_gameData->textBox.size() < 6 || isClosed(_gameData->textBox[0]))
        return;
    for (size_t i = 0; i < this->_gameData->broadcastResp.size(); i++) {
        addText(_gameData->textBox[5], i, _gameData->broadcastResp[i]);
    }
}

void Gui::TextBox::updateOnePlayerInfo()
{
    if (_gameData->rayInfo.type == PLAYER && _gameData->textBox.size() > 1) {
        _gameData->textBox[1]._state = NO_BUTTON;
        for (auto &player : _gameData->playerList) {
            if (player.n == _gameData->rayInfo.id) {
                addText(_gameData->textBox[1], 0, "Player: " + std::to_string(player.n));
                addText(_gameData->textBox[1], 1, "Level: " + std::to_string(player.level));
                addText(_gameData->textBox[1], 2, "Orientation: " + std::to_string(player.orientation));
                addText(_gameData->textBox[1], 3, "Position: (" + std::to_string((int)player.real_pos.x) + ", " + std::to_string((int)player.real_pos.y) + ")");
                addText(_gameData->textBox[1], 4, "Inventory:");
                addText(_gameData->textBox[1], 5, "Food: " + std::to_string(player.inventory[FOOD]));
                addText(_gameData->textBox[1], 6, "Linemate: " + std::to_string(player.inventory[LINEMATE]));
                addText(_gameData->textBox[1], 7, "Deraumere: " + std::to_string(player.inventory[DERAUMERE]));
                addText(_gameData->textBox[1], 8, "Sibur: " + std::to_string(player.inventory[SIBUR]));
                addText(_gameData->textBox[1], 9, "Mendiane: " + std::to_string(player.inventory[MENDIANE]));
                addText(_gameData->textBox[1], 10, "Phiras: " + std::to_string(player.inventory[PHIRAS]));
                addText(_gameData->textBox[1], 11, "Thystame: " + std::to_string(player.inventory[THYSTAME]));
            }
        }
    } else {
        _gameData->textBox[1]._state = NOT_SHOWN;
    }
}

void Gui::TextBox::updateOneTileInfo()
{
    if (_gameData->rayInfo.type == ISLAND && _gameData->textBox.size() > 2 && _gameData->objectPos.size() > 0) {
        _gameData->textBox[2]._state = NO_BUTTON;
        addText(_gameData->textBox[2], 0, "Tile: (" + std::to_string(_gameData->rayInfo.x) + ", " + std::to_string(_gameData->rayInfo.y) + ")");
        addText(_gameData->textBox[2], 1, "Food: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][FOOD]));
        addText(_gameData->textBox[2], 2, "Linemate: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][LINEMATE]));
        addText(_gameData->textBox[2], 3, "Deraumere: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][DERAUMERE]));
        addText(_gameData->textBox[2], 4, "Sibur: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][SIBUR]));
        addText(_gameData->textBox[2], 5, "Mendiane: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][MENDIANE]));
        addText(_gameData->textBox[2], 6, "Phiras: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][PHIRAS]));
        addText(_gameData->textBox[2], 7, "Thystame: " + std::to_string(_gameData->objectPos[_gameData->rayInfo.y][_gameData->rayInfo.x][THYSTAME]));
    } else {
        _gameData->textBox[2]._state = NOT_SHOWN;
    }
}

void Gui::TextBox::updateSlideBar(const Gui::Event &events)
{
    if (events.isKeyDown == true && events.mouse.x >= this->_gameData->infoSlider.sliderBar.pos.x - 0.004 * events.windowSize.width && events.mouse.x <= (this->_gameData->infoSlider.sliderBar.pos.x + this->_gameData->infoSlider.sliderBar.size.width) - 0.007 * events.windowSize.width) {
        int newXPos = this->_gameData->infoSlider.sliderBar.pos.x - 0.007;
        int newWidth = (this->_gameData->infoSlider.sliderBar.pos.x + this->_gameData->infoSlider.sliderBar.size.width) - 0.007 * events.windowSize.width;

        this->_gameData->infoSlider.sliderValue = ((events.mouse.x - newXPos) / newWidth) * 100;
        this->_gameData->infoSlider.sliderValue = ((this->_gameData->infoSlider.sliderValue * 150) / 100) * 6;

        this->_gameData->infoSlider.sliderHandle.pos.x = events.mouse.x;
        if (this->_gameData->infoSlider.sliderValue <= 0) {
            this->_gameData->infoSlider.sliderValue = 1;
        } else if (this->_gameData->infoSlider.sliderValue > 150) {
            this->_gameData->infoSlider.sliderValue = 150;
        }
        this->_client->send("sst " + std::to_string(this->_gameData->infoSlider.sliderValue) + "\n");
    }
}

void Gui::TextBox::update(const Gui::Event &events)
{
    updateGeneralInfo();
    updateListPlayerLevel();
    updateServerResp();
    updateBroadcastResp();
    updateOnePlayerInfo();
    updateOneTileInfo();
    updateSlideBar(events);
    for (auto &event : events.eventType) {
        if (event == Gui::EventType::WINDOW_RESIZED) {
            resize(_gameData->windowX, _gameData->windowY);
        }
        if (event == Gui::EventType::LEFT_CLICK) {
            openClose(events);
        }
    }
}
