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
    if (IsWindowResized()) {
        event.eventType.push_back(Gui::EventType::WINDOW_RESIZED);
        event.window_size_x = GetScreenWidth();
        event.window_size_y = GetScreenHeight();
    }
    if (IsKeyPressed(KEY_P)) {
        event.eventType.push_back(Gui::EventType::KEY_P);
    }
    if (IsKeyPressed(KEY_I)) {
        event.eventType.push_back(Gui::EventType::KEY_I);
    }
    if (IsKeyPressed(KEY_O)) {
        event.eventType.push_back(Gui::EventType::KEY_O);
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        event.eventType.push_back(Gui::EventType::LEFT_CLICK);
        event.mouse_x = GetMouseX();
        event.mouse_y = GetMouseY();
    }
    return event;
}
