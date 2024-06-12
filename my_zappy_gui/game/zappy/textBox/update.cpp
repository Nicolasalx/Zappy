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
    if (isClosed(_gameData->textBox[0]))
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
    if (isClosed(_gameData->textBox[0]))
        return;
    addText(_gameData->textBox[0], 0, "Number of players: " + std::to_string(_gameData->playerList.size()));
    addText(_gameData->textBox[0], 1, "Server frequency: " + std::to_string(_gameData->timeUnit));
}

void Gui::TextBox::updateServerResp()
{
    if (isClosed(_gameData->textBox[0]))
        return;
    for (size_t i = 0; i < this->_gameData->serverResp.size(); i++) {
        addText(_gameData->textBox[4], i, _gameData->serverResp[i]);
    }
}

void Gui::TextBox::update(const Gui::Event &events)
{
    updateGeneralInfo();
    updateListPlayerLevel();
    updateServerResp();
    for (auto &event : events.eventType) {
        if (event == Gui::EventType::WINDOW_RESIZED) {
            resize(_gameData->windowX, _gameData->windowY);
        }
        if (event == Gui::EventType::LEFT_CLICK) {
            openClose(events);
        }
    }
}
