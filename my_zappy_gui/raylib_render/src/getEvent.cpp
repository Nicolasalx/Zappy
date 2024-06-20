/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getEvent
*/

#include "Raylib.hpp"

void Gui::Raylib::putEventInBuffer(Gui::Event &event, std::string &bufferToFill)
{
    int charPressed = GetCharPressed();

    if (charPressed == 0) {
        return;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        event.eventType.push_back(Gui::EventType::ENTER);
    } else if (charPressed == 61) {
        if (!bufferToFill.empty()) {
            bufferToFill.pop_back();
            event.eventType.push_back(Gui::EventType::BACK_SPACE);
        }
    } else {
        bufferToFill += (char) charPressed;
    }
}

void Gui::Raylib::putEventInEventList(Gui::Event &event)
{
    for (const auto &currentKey : this->_keyBind) {
        if (IsKeyPressed(currentKey.first)) {
            event.eventType.push_back(currentKey.second);
        }
    }
}

void Gui::Raylib::handleKeyEvent(Gui::Event event)
{
    if (IsKeyPressed(KEY_M)) {
        event.eventType.push_back(Gui::EventType::KEY_M);
    }
    if (IsKeyPressed(KEY_N)) {
        event.eventType.push_back(Gui::EventType::NEXT_DISPLAY);
    }
    if (IsKeyPressed(KEY_I)) {
        event.eventType.push_back(Gui::EventType::KEY_I);
    }
    if (IsKeyPressed(KEY_O)) {
        event.eventType.push_back(Gui::EventType::KEY_O);
    }
    if (IsKeyPressed(KEY_C)) {
        Gui::RenderEndGame::_isEndGame = true;
    }
    if (IsKeyPressed(KEY_F))
        ToggleFullscreen();
}

void Gui::Raylib::getKeyEvent(Gui::Event &event)
{
    std::string bufferToFill;

    if (this->menu.inputSelect == IP) {
        bufferToFill = this->_event.bufferIP;
    } else if (this->menu.inputSelect == PORT) {
        bufferToFill = this->_event.bufferPort;
    } else if (this->menu.inputSelect == TEAM_NAME) {
        bufferToFill = this->_event.bufferTeamName;
    }
    if (this->_ignoreKey) {
        this->putEventInBuffer(event, bufferToFill);
    } else {
        this->putEventInEventList(event);
        handleKeyEvent(event);
    }
    if (this->menu.inputSelect == IP) {
        _event.bufferIP = bufferToFill;
        event.bufferIP = bufferToFill;
    } else if (this->menu.inputSelect == PORT) {
        _event.bufferPort = bufferToFill;
        event.bufferPort = bufferToFill;
    } else if (this->menu.inputSelect == TEAM_NAME) {
        _event.bufferTeamName = bufferToFill;
        event.bufferTeamName = bufferToFill;
    }
}

Gui::Event Gui::Raylib::getEvent()
{
    Gui::Event event;

    event.frame_time = GetFrameTime();
    if (WindowShouldClose()) {
        event.eventType.push_back(Gui::EventType::EXIT);
    }
    if (IsWindowResized() || window.launched == false) {
        event.eventType.push_back(Gui::EventType::WINDOW_RESIZED);
        window.windowSize.width = GetScreenWidth();
        window.windowSize.height = GetScreenHeight();
        window.launched = true;
    }
    if (this->menu.stateGame == IN_LEAVE) {
        event.eventType.push_back(Gui::EventType::EXIT);
    }
    if (this->menu.needToResize == true) { // ! Don't touch i will modify it (Nico)
        // event.eventType.push_back(Gui::EventType::NEXT_DISPLAY);
        // event.eventType.push_back(Gui::EventType::NEXT_DISPLAY);
        this->menu.needToResize = false;
    }
    if (this->textBoxList->_changeDisplayLib) {
        event.eventType.push_back(Gui::EventType::NEXT_DISPLAY);
    }

    getKeyEvent(event);
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        event.isKeyDown = true;
    } else {
        event.isKeyDown = false;
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        event.eventType.push_back(Gui::EventType::LEFT_CLICK);
    }
    event.mouse.x = GetMouseX();
    event.mouse.y = GetMouseY();
    event.windowSize.width = window.windowSize.width;
    event.windowSize.height = window.windowSize.height;

    this->island->changeIslandEvent();

    this->camera.handle_cursor();
    this->camera.update(menu.stateGame);
    this->camera.updatePlayerPos(event);

    this->rayInfo->addRayToEvent(event);

    this->camera.setPlayerEndGamePos(this->endGame->x,
    this->endGame->y, this->endGame->z);
    return event;
}
