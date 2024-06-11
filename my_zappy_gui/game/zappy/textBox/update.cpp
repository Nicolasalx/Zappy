/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateTextBox
*/

#include "TextBox.hpp"

void Gui::TextBox::addText(TextBoxData &textBox, size_t index, std::string text)
{
    if (textBox._text.size() < index + 1) {
        textBox._text.push_back(text);
    } else {
        textBox._text[index] = text;
    }
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

void Gui::TextBox::updateGeneralInfo()
{
    addText(_gameData->textBox[0], 0, "Number of players: " + std::to_string(_gameData->playerList.size()));
    addText(_gameData->textBox[1], 1, "Server frequency: " + std::to_string(_gameData->timeUnit));
}

void Gui::TextBox::update(const Gui::Event &events)
{
    updateGeneralInfo();
    for (auto &event : events.eventType) {
        if (event == Gui::EventType::WINDOW_RESIZED) {
            resize(_gameData->windowX, _gameData->windowY);
        }
        if (event == Gui::EventType::LEFT_CLICK) {
            openClose(events);
        }
    }
}
