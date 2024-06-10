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
    if (WindowShouldClose()) {
        event.eventType.push_back(Gui::EventType::EXIT);
    }
    if (IsWindowResized()) {
        event.eventType.push_back(Gui::EventType::WINDOW_RESIZED);
        window.sizeWindow.height = GetScreenHeight();
        window.sizeWindow.width = GetScreenWidth();
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
        event.mouse_x = GetMouseX();
        event.mouse_y = GetMouseY();
    }
    event.window_size_x = window.sizeWindow.height;
    event.window_size_y = window.sizeWindow.width;
    this->camera.handle_cursor();
    this->camera.update();
    return event;
}
