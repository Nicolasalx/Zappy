/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initMenu
*/

#include "Menu.hpp"

void Gui::Menu::addBox(const Box &box)
{
    this->_component.box = { box.x, box.y, box.width, box.height, box.color };
    this->_component.stockStartData.box = box;
}

void Gui::Menu::addText(const Text &text)
{
    this->_component.text = text;
}

void Gui::Menu::addComponent(ComponentType cmpType)
{
    this->_component.componentType = cmpType;
    this->_gameData->dataMenu.componentList.push_back(_component);
    this->_component.componentType = NONE;
}

void Gui::Menu::componentPlay()
{
    addBox({Box(0.4, 0.2, 0.3, 0.2, GRAY_COLOR)});
    addText(Text("PLAY", { 0.4, 0.4 }, 20, GRAY_COLOR));

    addComponent(PLAY);
}

Gui::Menu::Menu(std::shared_ptr<Gui::GameData> gameData) : _gameData(gameData)
{
    componentPlay();
}
