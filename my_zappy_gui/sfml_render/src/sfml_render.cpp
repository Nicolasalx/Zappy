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
    this->textBoxList = std::make_unique<Gui::SFMLRenderTextBoxList>();
}

Gui::SFMLRender::~SFMLRender()
{
}

Gui::Event Gui::SFMLRender::getEvent()
{
    Gui::Event guiEvent;
    sf::Event event;

    guiEvent.frame_time = clock.restart().asSeconds();
    // std::cout << "frame time: " << guiEvent.frame_time << std::endl;
    if (!window.isOpen()) {
        return Gui::Event();
    }
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    guiEvent.mouse.x = mousePos.x;
    guiEvent.mouse.y = mousePos.y;
    guiEvent.windowSize.width = window.getSize().x;
    guiEvent.windowSize.height = window.getSize().y;
    
    while (window.pollEvent(event)) {
        if (this->textBoxList->_changeDisplayLib) {
            std::cout << "printed\n";
            guiEvent.eventType.push_back(Gui::EventType::NEXT_DISPLAY);
        }
        if (event.type == sf::Event::Closed
        || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            guiEvent.eventType.push_back(Gui::EventType::EXIT);
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
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
    sf::Texture newTexture;
    sf::Sprite sprite;
    sf::Font font;
    if (!font.loadFromFile("bonus/assets/font.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return;
    }
    newTexture.loadFromFile("bonus/assets/background.png");
    sprite.setTexture(newTexture);
    if (!window.isOpen()) {
        return;
    }
    const Gui::Event &eventList = this->getEvent();
    window.clear();
    window.draw(sprite);
    this->map->render(gameData, window);
    this->object->render(gameData, window);
    this->egg->render(gameData, window);
    this->player->render(gameData, window);
    this->textBoxList->drawAllTextBoxs(window, font, gameData);
    if (std::find(eventList.eventType.begin(), eventList.eventType.end(), Gui::EventType::LEFT_CLICK) != eventList.eventType.end()) {
        sf::Vector2i cell = getClickedCase(gameData, eventList.mouse.x, eventList.mouse.y);
        if (cell.x < 0 && cell.y < 0) {
            std::cout << "Case clicked: (" << cell.x << ", " << cell.y << ")\n";
        }
    }
    window.display();
}

sf::Vector2i Gui::SFMLRender::getClickedCase(const GameData &gameData, int mouse_x, int mouse_y)
{
    double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
    double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
    double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;

    int cell_x = (mouse_x - offset_x) / cell_size;
    int cell_y = (mouse_y - offset_y) / cell_size;

    if (cell_x >= 0 && cell_x < gameData.mapSize.x && cell_y >= 0 && cell_y < gameData.mapSize.y) {
        return sf::Vector2i(cell_x, cell_y);
    }
    return sf::Vector2i(-1, -1);
}
