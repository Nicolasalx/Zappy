/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#include "SFMLRenderTextBox.hpp"

void Gui::SFMLRenderTextBox::addText(sf::RenderWindow &window, const std::string &text, float ypos, const sf::Font &font)
{
    sf::Text sfText;
    sfText.setFont(font);
    sfText.setString(text);
    sfText.setFillColor(sf::Color::White);
    sfText.setCharacterSize(static_cast<unsigned int>((_box.width * 2) * _boxInfo._text_size));

    sfText.setPosition(_box.left + _box.width * 0.1f, _box.top + _box.height * ypos);
    window.draw(sfText);
}

void Gui::SFMLRenderTextBox::draw(sf::RenderWindow &window, const sf::Font &font)
{
    if (_boxInfo._state == NOT_SHOWN)
        return;
    sf::RectangleShape mainBox(sf::Vector2f(_box.width, _box.height));
    mainBox.setPosition(_box.left, _box.top);
    mainBox.setFillColor(_color);
    mainBox.setOutlineThickness(1);
    mainBox.setOutlineColor(sf::Color::White);
    window.draw(mainBox);

    if (_boxInfo._state != NO_BUTTON) {
        sf::RectangleShape button(sf::Vector2f(_button.width, _button.height));
        button.setPosition(_button.left, _button.top);
        button.setFillColor(_color);
        button.setOutlineThickness(1);
        button.setOutlineColor(sf::Color::White);
        window.draw(button);
    }
    for (size_t i = 0; i < _boxInfo._text.size(); i++) {
        addText(window, _boxInfo._text[i], ((float)i + 0.5f) / (float)(_boxInfo._text.size() + 0.7f), font);
    }
}
