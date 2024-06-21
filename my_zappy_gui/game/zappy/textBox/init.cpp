/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initTextBox
*/

#include "TextBox.hpp"

Gui::TextBoxData::TextBoxData(float x, float y, float width, float height, float textSize, int state)
{
    this->_pos = {x, y};
    this->_size = {width, height};
    this->_real_pos = {0.0f, 0.0f};
    this->_real_size = {0.0f, 0.0f};
    this->_text_size = textSize;
    this->_buttonPos = {0.0f, 0.0f};
    this->_buttonSize = {0.0f, 0.0f};
    this->_state = state;
    this->_text = {};
}

void Gui::TextBox::initSlideBar()
{
    this->_gameData->infoSlider.sliderBar.size = {0.17, 0.01};
    this->_gameData->infoSlider.sliderBar.pos = {0.79, 0.165};
    this->_gameData->infoSlider.sliderBar.color = GRAY_COLOR;
    this->_gameData->infoSlider.sliderBar.realSize = this->_gameData->infoSlider.sliderBar.size;
    this->_gameData->infoSlider.sliderBar.realPos = this->_gameData->infoSlider.sliderBar.pos;
    this->_gameData->infoSlider.sliderHandle.size = {0.009, 0.03};
    this->_gameData->infoSlider.sliderHandle.pos = {0.88, 0.155};
    this->_gameData->infoSlider.sliderHandle.realSize = this->_gameData->infoSlider.sliderHandle.size;
    this->_gameData->infoSlider.sliderHandle.realPos = this->_gameData->infoSlider.sliderHandle.pos;
    this->_gameData->infoSlider.sliderHandle.color = BLUE_COLOR;
    // this->_gameData->infoSlider.sliderValue = this->_gameData->timeUnit;
}

void Gui::TextBox::initButtonNextDisplay()
{
    this->_gameData->infoWindow.buttonNextDisplay.pos = {0.38, 0.0};
    this->_gameData->infoWindow.buttonNextDisplay.size = {0.21, 0.1};
    this->_gameData->infoWindow.buttonNextDisplay.color = WHITE_COLOR;
    this->_gameData->infoWindow.buttonNextDisplay.realPos = this->_gameData->infoWindow.buttonNextDisplay.pos;
    this->_gameData->infoWindow.buttonNextDisplay.realSize = this->_gameData->infoWindow.buttonNextDisplay.size;

    this->_gameData->infoWindow.textButtonNextDisp.contentText = "Switch to SFML";
    this->_gameData->infoWindow.textButtonNextDisp.fontSize = 35;
    this->_gameData->infoWindow.textButtonNextDisp.pos = {0.42, 0.035};
    this->_gameData->infoWindow.textButtonNextDisp.realPos = this->_gameData->infoWindow.textButtonNextDisp.pos;
    this->_gameData->infoWindow.textButtonNextDisp.color = WHITE_COLOR;
}

Gui::TextBox::TextBox(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client) : _gameData(gameData), _client(client)
{
    TextBoxData boxInfo(0.77f, 0.04f, 0.21f, 0.21f, 0.038, LEFT_BUTTON);
    _gameData->textBox.push_back(boxInfo);
    TextBoxData boxInfo1(0.77f, 0.50f, 0.21f, 0.48f, 0.040, 0);
    _gameData->textBox.push_back(boxInfo1);
    TextBoxData boxInfo2(0.77f, 0.53f, 0.21f, 0.40f, 0.040, 0);
    _gameData->textBox.push_back(boxInfo2);
    TextBoxData boxInfo3(0.01f, 0.57f, 0.15f, 0.40f, 0.053, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo3);
    TextBoxData boxInfo4(0.01f, 0.04f, 0.15f, 0.51f, 0.030, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo4);
    TextBoxData boxInfo5(0.77f, 0.27f, 0.21f, 0.21f, 0.038, LEFT_BUTTON);
    _gameData->textBox.push_back(boxInfo5);
    listLevelPlayer.resize(8);
    initSlideBar();
    initButtonNextDisplay();
}
