/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initTextBox
*/

#include "TextBox.hpp"
#include "InfoGame.hpp"

static void resizeEachBox(Gui::TextBoxData &textBox, int window_width, int window_height)
{
    if (textBox._state == Gui::NO_BUTTON || textBox._state == Gui::RIGHT_BUTTON || textBox._state == Gui::LEFT_BUTTON || textBox._state == Gui::NOT_SHOWN) {
        textBox._real_pos.x = textBox._pos.x * window_width;
        textBox._real_pos.y = textBox._pos.y * window_height;
        textBox._real_size.x = textBox._size.x * window_width;
        textBox._real_size.y = textBox._size.y * window_height;
        if (textBox._state == Gui::RIGHT_BUTTON) {
            textBox._buttonPos = {
                textBox._real_pos.x + textBox._real_size.x - (window_width + window_height) * 0.01f,
                textBox._real_pos.y
            };
            textBox._buttonSize = {(window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
        if (textBox._state == Gui::LEFT_BUTTON) {
            textBox._buttonPos = {textBox._real_pos.x, textBox._real_pos.y};
            textBox._buttonSize = {(window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    } else {
        if (textBox._state == Gui::CLOSED_RIGHT) {
            textBox._real_pos = {-window_width * textBox._size.x + (window_width + window_height) * 0.01f, window_height * textBox._pos.y};
            textBox._real_size = {window_width * textBox._size.x, window_height * textBox._size.y};
            textBox._buttonPos = {textBox._real_pos.x + textBox._real_size.x - (window_width + window_height) * 0.01f, textBox._real_pos.y};
            textBox._buttonSize = {(window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
        if (textBox._state == Gui::CLOSED_LEFT) {
            textBox._real_pos = {window_width - (window_width + window_height) * 0.01f, window_height * textBox._pos.y};
            textBox._real_size = {window_width * textBox._size.x, window_height * textBox._size.y};
            textBox._buttonPos = {textBox._real_pos.x, textBox._real_pos.y};
            textBox._buttonSize = {(window_width + window_height) * 0.01f, (window_width + window_height) * 0.01f};
        }
    }
}

void Gui::TextBox::resizeSlideBar(int windowWidth, int windowHeight)
{
    this->_gameData->infoSlider.sliderBar.pos = { windowWidth * this->_gameData->infoSlider.sliderBar.realPos.x, windowHeight * this->_gameData->infoSlider.sliderBar.realPos.y };
    this->_gameData->infoSlider.sliderBar.size = { windowWidth * this->_gameData->infoSlider.sliderBar.realSize.width, windowHeight * this->_gameData->infoSlider.sliderBar.realSize.height };

    this->_gameData->infoSlider.sliderHandle.pos = { windowWidth * this->_gameData->infoSlider.sliderHandle.realPos.x, windowHeight * this->_gameData->infoSlider.sliderHandle.realPos.y };
    this->_gameData->infoSlider.sliderHandle.size = { windowWidth * this->_gameData->infoSlider.sliderHandle.realSize.width, windowHeight * this->_gameData->infoSlider.sliderHandle.realSize.height };
}

void Gui::TextBox::resizeButtonNextDisp(int windowWidth, int windowHeight)
{
    this->_gameData->infoWindow.buttonNextDisplay.pos = { windowWidth * this->_gameData->infoWindow.buttonNextDisplay.realPos.x, windowHeight * this->_gameData->infoWindow.buttonNextDisplay.realPos.y };
    this->_gameData->infoWindow.buttonNextDisplay.size = { windowWidth * this->_gameData->infoWindow.buttonNextDisplay.realSize.width, windowHeight * this->_gameData->infoWindow.buttonNextDisplay.realSize.height };
}

void Gui::TextBox::resizeButtonPlayerMode(int windowWidth, int windowHeight)
{
    for (auto &button: this->_gameData->playerMode.buttonPlayerMode) {
        button.button.pos = { windowWidth * button.button.realPos.x, windowHeight * button.button.realPos.y };
        button.button.size = { windowWidth * button.button.realSize.width, windowHeight * button.button.realSize.height };
        button.text.pos = { windowWidth * button.text.realPos.x, windowHeight * button.text.realPos.y };
    }
}

void Gui::TextBox::resize(int windowWidth, int windowHeight)
{
    for (auto &box : _gameData->textBox) {
        resizeEachBox(box, windowWidth, windowHeight);
    }
    resizeSlideBar(windowWidth, windowHeight);
    resizeButtonNextDisp(windowWidth, windowHeight);
    resizeButtonPlayerMode(windowWidth, windowHeight);
}
