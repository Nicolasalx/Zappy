/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handleEvent
*/

#include "Menu.hpp"

bool Gui::Menu::isMouseOnBox(const Box &box, const Pos &mousePos)
{
    float boxLeft = box.x;
    float boxRight = box.x + box.width;
    float boxTop = box.y;
    float boxBottom = box.y + box.height;

    if (mousePos.x >= boxLeft && mousePos.x <= boxRight &&
        mousePos.y >= boxTop && mousePos.y <= boxBottom) {
        return true;
    } else {
        return false;
    }
}

float areaOfTriangle(const Gui::Pos &a, const Gui::Pos &b, const Gui::Pos &c)
{
    return std::abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

bool isMouseOnTriangle(const Gui::Triangle &triangle, const Gui::Pos &mousePos)
{
    if (triangle.topVertex.x == 0) {
        return false;
    }
    float areaOrig = areaOfTriangle(triangle.topVertex, triangle.bottomLeftVertex, triangle.bottomRightVertex);

    float area1 = areaOfTriangle(mousePos, triangle.topVertex, triangle.bottomLeftVertex);
    float area2 = areaOfTriangle(mousePos, triangle.topVertex, triangle.bottomRightVertex);
    float area3 = areaOfTriangle(mousePos, triangle.bottomLeftVertex, triangle.bottomRightVertex);

    return std::abs(areaOrig - (area1 + area2 + area3)) <= 0.01;
}

bool Gui::Menu::isMousePressed(const Gui::Event &event)
{
    for (const auto &evt: event.eventType) {
        switch (evt) {
            case Gui::EventType::LEFT_CLICK:
                return true;
            default:
                break;
        }
    }
    return false;
}

void Gui::Menu::checkMouseState(const Gui::Event &event, Component &component)
{
    if (this->_gameData->ignoreKey && component.componentType == INPUT_BOX_IP) {
        component.text.contentText = event.buffer;
    }
    if (!isMousePressed(event)) {
        return;
    }
    if (component.componentType == SPECTATOR_MODE) {
        this->_gameData->dataMenu.stateGame = TRY_SPECTATOR_MODE;
    } else if (component.componentType == INPUT_BOX_IP) {
        this->_gameData->dataMenu.cursorState = SELECTIONNED;
        this->_gameData->ignoreKey = true;
    } else if (component.componentType == PLAYER_MODE) {
        this->_gameData->dataMenu.stateGame = TRY_PLAYER_MODE;
    } else if (component.componentType == SETTINGS) {
        this->_gameData->dataMenu.stateGame = IN_SETTINGS;
    } else if (component.componentType == QUIT) {
        this->_gameData->dataMenu.stateGame = IN_LEAVE;
    } else if (component.componentType == GO_BACK_TO_MENU) {
        this->_gameData->dataMenu.stateGame = IN_MENU;
    } else {
        this->_gameData->dataMenu.cursorState = DEFAULT;
        this->_gameData->ignoreKey = false;
    }
}

void Gui::Menu::handleEventSettings(Component &component, const Gui::Event &event)
{
    if (isMouseOnTriangle(component.settingsComponent.triangleRight, event.mouse) && isMousePressed(event)) {
        if (component.componentType == MODIFY_RESOLUTION) {
            if ((std::size_t)_idxOptionResolution + 1 >= _optionResolution.size()) {
                _idxOptionResolution = 0;
            } else {
                _idxOptionResolution += 1;
            }
            component.text.contentText = _optionResolution.at(_idxOptionResolution).resText;
            this->_gameData->infoWindow.resolution = _optionResolution.at(_idxOptionResolution).windowSize;
        } else if (component.componentType == MODIFY_VOLUME && this->_gameData->infoWindow.volume + 10 <= 100) {
            this->_gameData->infoWindow.volume += 10;
            component.text.contentText = std::to_string(this->_gameData->infoWindow.volume) + " %";
        }
        component.settingsComponent.triangleRight.color = RED_COLOR;
    } else if (isMouseOnTriangle(component.settingsComponent.triangleLeft, event.mouse) && isMousePressed(event)) {
        if (component.componentType == MODIFY_RESOLUTION) {
            if (_idxOptionResolution - 1 < 0) {
                _idxOptionResolution = 2;
            } else {
                _idxOptionResolution -= 1;
            }
            component.text.contentText = _optionResolution.at(_idxOptionResolution).resText;
            this->_gameData->infoWindow.resolution = _optionResolution.at(_idxOptionResolution).windowSize;
        } else if (component.componentType == MODIFY_VOLUME && this->_gameData->infoWindow.volume - 10 >= 0) {
            this->_gameData->infoWindow.volume -= 10;
            component.text.contentText = std::to_string(this->_gameData->infoWindow.volume) + " %";
        }
        component.settingsComponent.triangleLeft.color = RED_COLOR;
    } else {
        component.settingsComponent.triangleLeft.color = WHITE_COLOR;
        component.settingsComponent.triangleRight.color = WHITE_COLOR;
    }
}

void Gui::Menu::handleEvent(const Gui::Event &event)
{
    for (auto &component: this->_gameData->dataMenu.componentList) {
        if (isMouseOnBox(component.box, event.mouse)) {
            component.box.color = RED_COLOR;
            checkMouseState(event, component);
        } else if (component.componentType == MODIFY_RESOLUTION || component.componentType == MODIFY_VOLUME) {
            handleEventSettings(component, event);
        } else {
            component.box.color = WHITE_COLOR;
        }
    }

    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Gui::EventType::KEY_M:
                this->_gameData->dataMenu.stateGame = IN_MENU;
                break;
            default:
                break;
        }
    }
}
