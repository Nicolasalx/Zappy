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
    this->_gameData->infoSlider.sliderValue = 50;
}

void Gui::TextBox::initButtonNextDisplay()
{
    this->_gameData->infoWindow.buttonNextDisplay.pos = {0.38, 0.0};
    this->_gameData->infoWindow.buttonNextDisplay.size = {0.21, 0.1};
    this->_gameData->infoWindow.buttonNextDisplay.color = WHITE_COLOR;
    this->_gameData->infoWindow.buttonNextDisplay.realPos = this->_gameData->infoWindow.buttonNextDisplay.pos;
    this->_gameData->infoWindow.buttonNextDisplay.realSize = this->_gameData->infoWindow.buttonNextDisplay.size;
}

void Gui::TextBox::addButtonPlayerMode(const std::string &contentText, Pos pos, const SizeButton &sizeButton, ActionButtonPlayer actPlayer)
{
    ButtonPlayerMode buttonPlayerMode;
    Size size;
    Pos posText;

    if (sizeButton == BIG) {
        size = { 0.18, 0.21 };
        posText = {pos.x + 0.05f, pos.y - 0.03f };
    } else if (sizeButton == MIDDLE) {
        size = {0.06, 0.1};
        posText = pos;
    } else {
        posText = pos;
        size = {0.035, 0.06};
    }
    buttonPlayerMode.button = {.pos = pos, .size = size, .realPos = pos, .realSize = size, .color = WHITE_COLOR};
    buttonPlayerMode.text = {.contentText = contentText, .pos = posText, .realPos = posText, .fontSize = 15, .color = BLACK_COLOR};
    buttonPlayerMode.actPlayer = actPlayer;
    this->_gameData->playerMode.buttonPlayerMode.push_back(buttonPlayerMode);
}

void Gui::TextBox::turnLeft()
{
    std::cout << "TURN LEFT\n";
}

void Gui::TextBox::initButtonPlayerMode()
{
    Pos pos = {0.2, 0.88};

    addButtonPlayerMode("LEFT", pos, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("FORWARD", {pos.x + 0.035f, pos.y - 0.11f}, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("RIGHT", {pos.x + 0.07f, pos.y}, MIDDLE, std::bind(&TextBox::turnLeft, this));

    addButtonPlayerMode("LOOK", {pos.x + 0.15f, pos.y - 0.11f}, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("EJECT", {pos.x + 0.22f, pos.y - 0.11f}, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("INVENTORY", {pos.x + 0.15f, pos.y}, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("FORK", {pos.x + 0.22f, pos.y}, MIDDLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("INCANTATION", {pos.x + 0.29f, pos.y}, MIDDLE, std::bind(&TextBox::turnLeft, this));

    addButtonPlayerMode("TAKE OBJECT", {pos.x + 0.38f, pos.y - 0.11f}, BIG, NULL);
    addButtonPlayerMode("1", {pos.x + 0.385f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("2", {pos.x + 0.44f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("3", {pos.x + 0.49f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("4", {pos.x + 0.385f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("5", {pos.x + 0.425f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("6", {pos.x + 0.465f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("7", {pos.x + 0.505f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));

    addButtonPlayerMode("SET OBJECT", {pos.x + 0.58f, pos.y - 0.11f}, BIG, NULL);
    addButtonPlayerMode("1", {pos.x + 0.585f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("2", {pos.x + 0.64f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("3", {pos.x + 0.69f, pos.y - 0.10f}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("4", {pos.x + 0.585f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("5", {pos.x + 0.625f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("6", {pos.x + 0.665f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
    addButtonPlayerMode("7", {pos.x + 0.705f, pos.y}, LITTLE, std::bind(&TextBox::turnLeft, this));
}

Gui::TextBox::TextBox(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client) : _gameData(gameData), _client(client)
{
    TextBoxData boxInfo(0.77f, 0.04f, 0.21f, 0.21f, 0.038, LEFT_BUTTON);
    _gameData->textBox.push_back(boxInfo);
    TextBoxData boxInfo1(0.77f, 0.47f, 0.21f, 0.51f, 0.040, 0);
    _gameData->textBox.push_back(boxInfo1);
    TextBoxData boxInfo2(0.77f, 0.53f, 0.21f, 0.40f, 0.040, 0);
    _gameData->textBox.push_back(boxInfo2);
    TextBoxData boxInfo3(0.01f, 0.57f, 0.15f, 0.40f, 0.053, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo3);
    TextBoxData boxInfo4(0.01f, 0.04f, 0.15f, 0.51f, 0.030, RIGHT_BUTTON);
    _gameData->textBox.push_back(boxInfo4);
    TextBoxData boxInfo5(0.77f, 0.29f, 0.21f, 0.21f, 0.038, LEFT_BUTTON);
    _gameData->textBox.push_back(boxInfo5);
    listLevelPlayer.resize(8);
    initSlideBar();
    initButtonNextDisplay();
    initButtonPlayerMode();
}
