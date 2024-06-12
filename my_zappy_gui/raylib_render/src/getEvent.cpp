/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getEvent
*/

#include "Raylib.hpp"

// ! https://www.raylib.com/examples/text/loader.html?name=text_input_box

void Gui::Raylib::putEventInBuffer(Gui::Event &event)
{
    int charPressed = GetCharPressed();

    if (charPressed == 0) {
        return;
    }
    if (IsKeyPressed(KEY_ENTER)) {
        event.eventType.push_back(Gui::EventType::ENTER);
    } else if (charPressed == 61) { // ! Actually press '=' to delete one character
        event.buffer.pop_back();
        std::cout << "BUFF: " << event.buffer << "\n";
        _event.buffer = event.buffer;
    } else {
        _event.buffer += (char) charPressed;
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

void Gui::Raylib::getKeyEvent(Gui::Event &event)
{
    if (this->_ignoreKey) {
        this->putEventInBuffer(event);
    } else {
        this->putEventInEventList(event);
    }
    event.buffer = this->_event.buffer;
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
    getKeyEvent(event);

    if (IsKeyPressed(KEY_M)) {
        std::cout << "KEY M EVENT\n";
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

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        event.eventType.push_back(Gui::EventType::LEFT_CLICK);
    }
    event.mouse.x = GetMouseX();
    event.mouse.y = GetMouseY();
    event.windowSize.width = window.windowSize.width;
    event.windowSize.height = window.windowSize.height;
    this->camera.handle_cursor();
    this->camera.update();
    return event;
}
