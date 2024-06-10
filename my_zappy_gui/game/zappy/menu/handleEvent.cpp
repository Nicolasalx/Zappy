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

void Gui::Menu::checkMouseState(const Gui::Event &event, Component component)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Gui::EventType::LEFT_CLICK:
                if (component.componentType == PLAY) {
                    this->_gameData->dataMenu.gameIsLaunch = true;
                } else if (component.componentType == SETTINGS) {
                    
                }
            break;
            default:
                break;
        }
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
            case Gui::EventType::ESCAPE:
                this->_gameData->dataMenu.gameIsLaunch = false;
                break;
            default:
                break;
        }
    }
}
