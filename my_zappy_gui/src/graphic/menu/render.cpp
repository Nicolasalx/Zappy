/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::handleEventEachComponent(Gui::Component component)
{
    for (auto &box: component.boxes) {
        if (CheckCollisionPointRec(GetMousePosition(), box.box)) {
            std::cout << "ENTER: " << component.cmpType << "\n";
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                box.color = RED;
                if (component.cmpType == PLAY) {
                    // Not in menu
                    this->isInMenu = false;
                    std::cout << "MENU DESACTIVATE\n";
                }
            } else {
                box.color = GREEN;
            }
        } else {
            box.color = LIGHTGRAY;
        }
    }
}

void Gui::Menu::handleEventMenu()
{
    ClearBackground(RAYWHITE);

    for (auto &component: _componentList) {
        handleEventEachComponent(component);
    }
}

void Gui::Menu::resizeMenu(int window_width, int window_height)
{
    // this->box = { window_width / 2.0f - 100, window_height / 2.0f - 50, 200, 100 };
}

void Gui::Menu::render(Component &component)
{
    for (const auto &box: component.boxes) {
        DrawRectangleLinesEx(box.box, 3, box.color);
    }
    for (const auto &text: component.texts) {
        DrawText(text.contentText.c_str(), text.pos.x, text.pos.y, 20, text.color);
    }
}

void Gui::Menu::renderMenu()
{
    for (auto &item: _componentList) {
        render(item);
    }

    // for (const auto &box: _boxes) {
    //     DrawRectangleLinesEx(box, 3, boxColor);
    // }
// 
    // std::string text = "PLAY";
// 
    // int textWidth = MeasureText(text.c_str(), 20);
// 
    // for (const auto &text)
    // DrawText(text.c_str(), box.x + (box.width - textWidth) / 2, box.y + (box.height - 20) / 2, 20, boxColor);

    // Button Play
    // Button Settings
    // Button Quit
}
