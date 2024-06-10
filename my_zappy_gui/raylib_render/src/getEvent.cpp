/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** getEvent
*/

#include "Raylib.hpp"

Gui::Event Gui::Raylib::getEvent()
{
    Gui::Event event;

    event.frame_time = GetFrameTime();
    if (IsKeyDown(KEY_TAB)) {
        event.eventType.push_back(Gui::EventType::EXIT);
    }
    if (IsWindowResized()) {
        event.eventType.push_back(Gui::EventType::WINDOW_RESIZED);
        window.windowSize.width = GetScreenWidth();
        window.windowSize.height = GetScreenHeight();
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
    if (IsKeyDown(KEY_ESCAPE)) {
        event.eventType.push_back(Gui::EventType::ESCAPE);
    }
    event.mouse.x = GetMouseX();
    event.mouse.y = GetMouseY();
    event.windowSize.width = window.windowSize.width;
    event.windowSize.height = window.windowSize.height;
    this->camera.handle_cursor();
    this->camera.update();
    return event;
}
