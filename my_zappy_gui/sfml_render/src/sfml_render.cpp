/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sfml_render
*/

#include "SFMLRender.hpp"

extern "C"
{
    Gui::IRenderModule *entryPoint()
    {
        return new Gui::SFMLRender();
    }
}

Gui::SFMLRender::SFMLRender() : window(sf::VideoMode(1920, 1080), "ZAPPY")
{
    this->player = std::make_unique<Gui::SFMLRenderPlayer>();
    this->egg = std::make_unique<Gui::SFMLRenderEgg>();
    this->map = std::make_unique<Gui::SFMLRenderMap>();
    this->object = std::make_unique<Gui::SFMLRenderObject>();
}

Gui::SFMLRender::~SFMLRender()
{
}

Gui::Event Gui::SFMLRender::getEvent()
{
    Gui::Event guiEvent;
    sf::Event event;
    sf::Vector2i mousePos;

    if (!window.isOpen()) {
        return Gui::Event();
    }
    mousePos = sf::Mouse::getPosition(window);
    guiEvent.mouse.x = mousePos.x;
    guiEvent.mouse.y = mousePos.y;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            guiEvent.eventType.push_back(Gui::EventType::EXIT);
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            guiEvent.eventType.push_back(Gui::EventType::LEFT_CLICK);
        }
        for (const auto &currentKey : this->keyBind) {
            if (sf::Keyboard::isKeyPressed(currentKey.first)) {
                guiEvent.eventType.push_back(currentKey.second);
            }
        }
    }
    return guiEvent;
}

void Gui::SFMLRender::render(const Gui::GameData &gameData)
{
    if (window.isOpen()) {
        window.clear();
        this->map->render(gameData, window);
        this->object->render(gameData, window);
        this->egg->render(gameData, window);
        this->player->render(gameData, window);
        window.display();
    }
}
