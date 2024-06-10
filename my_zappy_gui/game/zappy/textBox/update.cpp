/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** updateTextBox
*/

#include "TextBox.hpp"

void Gui::TextBox::addText(TextBoxData &textBox, size_t index, std::string text)
{
    if (textBox.text.size() < index + 1) {
        textBox.text.push_back(text);
    } else {
        textBox.text[index] = text;
    }
}

void Gui::TextBox::resize(int window_width, int window_height)
{
    ;
}

void Gui::TextBox::updateGeneralInfo()
{
    addText(_gameData->textBox[0], 0, "Number of players: " + std::to_string(_gameData->playerList.size()));
    addText(_gameData->textBox[1], 1, "Server frequency: " + std::to_string(_gameData->timeUnit));
}

void Gui::TextBox::update(const Gui::Event &event)
{
    updateGeneralInfo();
}
