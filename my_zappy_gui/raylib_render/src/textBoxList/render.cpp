/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render textbox
*/

#include "RenderTextBox.hpp"
#include "RenderColor.hpp"

void Gui::RenderTextBoxList::updateTextBoxs(const GameData &gameData)
{
    while (_textBoxs.size() < gameData.textBox.size()) {
        RenderTextBox newTextBox(gameData.textBox[_textBoxs.size()]);
        _textBoxs.push_back(newTextBox);
    }
    for (size_t i = 0; i < gameData.textBox.size(); i++) {
        if (gameData.textBox[i]._text.size() != _textBoxs[i]._boxInfo._text.size()) {
            _textBoxs[i]._boxInfo._text = gameData.textBox[i]._text;
        }
    }
    for (size_t i = 0; i < _textBoxs.size(); i++) {
        _textBoxs[i]._box.x = gameData.textBox[i]._real_pos.x;
        _textBoxs[i]._box.y = gameData.textBox[i]._real_pos.y;
        _textBoxs[i]._box.width = gameData.textBox[i]._real_size.x;
        _textBoxs[i]._box.height = gameData.textBox[i]._real_size.y;
        _textBoxs[i]._button.x = gameData.textBox[i]._buttonPos.x;
        _textBoxs[i]._button.y = gameData.textBox[i]._buttonPos.y;
        _textBoxs[i]._button.width = gameData.textBox[i]._buttonSize.x;
        _textBoxs[i]._button.height = gameData.textBox[i]._buttonSize.y;
        _textBoxs[i]._boxInfo._state = gameData.textBox[i]._state;
        for (size_t j = 0; j < gameData.textBox[i]._text.size(); j++) {
            _textBoxs[i]._boxInfo._text[j] = gameData.textBox[i]._text[j];
        }
    }
}

void Gui::RenderTextBoxList::renderSlideBar(const GameData &gameData)
{
    this->stateGame = gameData.dataMenu.stateGame;
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
    DrawRectangle(gameData.infoSlider.sliderBar.pos.x, gameData.infoSlider.sliderBar.pos.y, gameData.infoSlider.sliderBar.size.width, gameData.infoSlider.sliderBar.size.height, Gui::RenderColor::getColorFromGame(gameData.infoSlider.sliderBar.color));
    DrawRectangle(gameData.infoSlider.sliderHandle.pos.x, gameData.infoSlider.sliderHandle.pos.y, gameData.infoSlider.sliderHandle.size.width, gameData.infoSlider.sliderHandle.size.height, Gui::RenderColor::getColorFromGame(gameData.infoSlider.sliderHandle.color));
}

void Gui::RenderTextBoxList::renderButtonNextDisp(const GameData &gameData)
{
    Color color = Gui::RenderColor::getColorFromGame(gameData.infoWindow.buttonNextDisplay.color);
    Rectangle box = Rectangle(gameData.infoWindow.buttonNextDisplay.pos.x, gameData.infoWindow.buttonNextDisplay.pos.y,
        gameData.infoWindow.buttonNextDisplay.size.width, gameData.infoWindow.buttonNextDisplay.size.height);

    color.a = 100;
    DrawRectangleRec(box, color);
    color.a = 255;
    DrawRectangleLinesEx(box, 1, color);
    if (gameData.infoWindow.changeDisplayLib == CHANGE && this->_changeDisplayLib != WAIT) {
        this->_changeDisplayLib = gameData.infoWindow.changeDisplayLib;
    }
    if (gameData.infoWindow.changeDisplayLib == DONT_CHANGE && this->_changeDisplayLib == WAIT) {
        this->_changeDisplayLib = DONT_CHANGE;
    }
    DrawText(gameData.infoWindow.textButtonNextDisp.contentText.c_str(), gameData.infoWindow.textButtonNextDisp.pos.x, gameData.infoWindow.textButtonNextDisp.pos.y, gameData.infoWindow.textButtonNextDisp.fontSize, Gui::RenderColor::getColorFromGame(gameData.infoWindow.textButtonNextDisp.color));
}

void Gui::RenderTextBoxList::render(const GameData &gameData)
{
    DrawFPS(10, 10);
    updateTextBoxs(gameData);
    renderSlideBar(gameData);
    renderButtonNextDisp(gameData);
    for (auto &textBox : _textBoxs) {
        textBox.draw();
    }
}
