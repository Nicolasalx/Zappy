/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#include "menu.hpp"

void Gui::Menu::handleEventEachComponent(Gui::Component &component)
{
    if (CheckCollisionPointRec(GetMousePosition(), component.box.rect)) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            component.box.color = RED;
            if (component.cmpType == PLAY) {
                this->isInMenu = false;
            }

        } else {
            component.box.color = GREEN;
        }
    } else {
        component.box.color = LIGHTGRAY;
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
    for (auto &component: _componentList) {
        component.box.rect = { window_width * component.infoCmp.infoBox.x, window_height * component.infoCmp.infoBox.y, window_width * component.infoCmp.infoBox.width, window_height * component.infoCmp.infoBox.height };
        component.text.pos = { window_width * component.infoCmp.posText.x, window_height * component.infoCmp.posText.y };
    }
}

void Gui::Menu::render(Component &component)
{
    DrawRectangleLinesEx(component.box.rect, 3, component.box.color);
    DrawText(component.text.contentText.c_str(), component.box.rect.x, component.box.rect.y, 20, component.box.color);
}

void Gui::Menu::renderMenu()
{
    std::cout << "OK\n";
    for (auto &item: _componentList) {
        std::cout << "OK\n";
        render(item);
    }
}
