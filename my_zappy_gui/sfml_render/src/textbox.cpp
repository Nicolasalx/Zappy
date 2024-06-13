/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** textbox
*/

#include "SFMLRenderTextBox.hpp"

Gui::SFMLRenderTextBox::SFMLRenderTextBox()
{
    ;
}

void Gui::SFMLRenderTextBox::render(const GameData &gameData, sf::RenderWindow &window)
{
    for (size_t i = 0; i < gameData.textBox.size(); ++i) {
        printf("TextBox: %s\n", gameData.textBox[i]._text);
    }
}
