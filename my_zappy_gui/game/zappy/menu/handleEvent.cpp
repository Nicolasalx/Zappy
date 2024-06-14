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

void Gui::Menu::checkMouseState(const Gui::Event &event, Component &component)
{
    // if (this->_gameData->dataMenu.stateGame == IN_SPECTATOR_MODE
    // || this->_gameData->dataMenu.stateGame == IN_PLAYER_MODE) {
    //     return;
    // }
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Gui::EventType::LEFT_CLICK:
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
            default:
                break;
        }
    }
    if (this->_gameData->ignoreKey && component.componentType == INPUT_BOX_IP) {
        component.text.contentText = event.buffer;
    }
}

void Gui::Menu::handleEvent(const Gui::Event &event)
{
    for (auto &component: this->_gameData->dataMenu.componentList) {
        if (isMouseOnBox(component.box, event.mouse)) {
            component.box.color = RED_COLOR;
            checkMouseState(event, component);
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
