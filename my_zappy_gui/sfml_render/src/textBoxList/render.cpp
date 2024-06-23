/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render textbox
*/

#include "SFMLRenderTextBox.hpp"

void Gui::SFMLRenderTextBoxList::updateTextBoxs(const GameData &gameData)
{
    while (_textBoxs.size() < gameData.textBox.size()) {
        SFMLRenderTextBox newTextBox(gameData.textBox[_textBoxs.size()]);
        _textBoxs.push_back(newTextBox);
    }
    for (size_t i = 0; i < gameData.textBox.size(); i++) {
        if (gameData.textBox[i]._text.size() != _textBoxs[i]._boxInfo._text.size()) {
            _textBoxs[i]._boxInfo._text = gameData.textBox[i]._text;
        }
    }
    for (size_t i = 0; i < _textBoxs.size(); i++) {
        _textBoxs[i]._box.left = gameData.textBox[i]._real_pos.x;
        _textBoxs[i]._box.top = gameData.textBox[i]._real_pos.y;
        _textBoxs[i]._box.width = gameData.textBox[i]._real_size.x;
        _textBoxs[i]._box.height = gameData.textBox[i]._real_size.y;
        _textBoxs[i]._button.left = gameData.textBox[i]._buttonPos.x;
        _textBoxs[i]._button.top = gameData.textBox[i]._buttonPos.y;
        _textBoxs[i]._button.width = gameData.textBox[i]._buttonSize.x;
        _textBoxs[i]._button.height = gameData.textBox[i]._buttonSize.y;
        _textBoxs[i]._boxInfo._state = gameData.textBox[i]._state;
        for (size_t j = 0; j < gameData.textBox[i]._text.size(); j++) {
            _textBoxs[i]._boxInfo._text[j] = gameData.textBox[i]._text[j];
        }
    }
}

void Gui::SFMLRenderTextBoxList::renderButtonNextDisp(sf::RenderWindow &window, const sf::Font &font, const GameData &gameData)
{
    sf::RectangleShape box(sf::Vector2f(gameData.infoWindow.buttonNextDisplay.size.width,
        gameData.infoWindow.buttonNextDisplay.size.height));
    box.setPosition(gameData.infoWindow.buttonNextDisplay.pos.x, gameData.infoWindow.buttonNextDisplay.pos.y);
    sf::Color color = {255, 255, 255};
    color.a = 100;
    box.setFillColor(color);
    color.a = 255;
    box.setOutlineColor(color);
    box.setOutlineThickness(1);
    window.draw(box);
    sf::Text text;
    text.setFont(font);
    text.setString("Switch to RAYLIB");
    text.setPosition(gameData.infoWindow.textButtonNextDisp.pos.x, gameData.infoWindow.buttonNextDisplay.pos.y);
    text.setCharacterSize(gameData.infoWindow.textButtonNextDisp.fontSize);
    window.draw(text);
    if (gameData.infoWindow.changeDisplayLib == CHANGE && this->_changeDisplayLib != WAIT) {
        this->_changeDisplayLib = gameData.infoWindow.changeDisplayLib;
    }
    if (gameData.infoWindow.changeDisplayLib == DONT_CHANGE && this->_changeDisplayLib == WAIT) {
        this->_changeDisplayLib = DONT_CHANGE;
    }
}

void Gui::SFMLRenderTextBoxList::renderSlideBar(sf::RenderWindow &window, const GameData &gameData)
{
    if (gameData.textBox.size() < 2) {
        return;
    }
    Gui::TextBoxData textBox = gameData.textBox.at(0);
    if (textBox._state == Gui::CLOSED_LEFT) {
        return;
    }
    if (gameData.dataMenu.stateGame == IN_PLAYER_MODE || gameData.dataMenu.stateGame == TRY_PLAYER_MODE) {
        return;
    }
    sf::RectangleShape slideBar(sf::Vector2f(gameData.infoSlider.sliderBar.size.width, gameData.infoSlider.sliderBar.size.height));
    slideBar.setPosition(gameData.infoSlider.sliderBar.pos.x, gameData.infoSlider.sliderBar.pos.y);
    slideBar.setFillColor(sf::Color(255, 255, 255));
    window.draw(slideBar);

    sf::RectangleShape handler(sf::Vector2f(gameData.infoSlider.sliderHandle.size.width, gameData.infoSlider.sliderHandle.size.height));
    handler.setPosition(gameData.infoSlider.sliderHandle.pos.x, gameData.infoSlider.sliderHandle.pos.y);
    handler.setFillColor(sf::Color(0, 0, 255));
    window.draw(handler);
}

void Gui::SFMLRenderTextBoxList::drawAllTextBoxs(sf::RenderWindow &window, const sf::Font &font, const GameData &gameData)
{
    updateTextBoxs(gameData);
    renderButtonNextDisp(window, font, gameData);
    renderSlideBar(window, gameData);
    for (auto &textBox : _textBoxs) {
        textBox.draw(window, font);
    }
}
