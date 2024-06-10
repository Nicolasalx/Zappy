/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** sfml_render
*/

#include "SFMLRender.hpp"

extern "C"
{
    Gui::IRenderModule *entryPoint(void)
    {
        return new Gui::SFMLRender();
    }
}

Gui::SFMLRender::SFMLRender() : window(sf::VideoMode(1920, 1080), "ZAPPY")
{
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
    std::vector<sf::Texture> egg_textures(gameData.eggList.size());
    for (size_t i = 0; i < gameData.eggList.size(); ++i) {
        if (!egg_textures[i].loadFromFile("bonus/assets/egg.png")) {
            std::cerr << "Error loading egg texture" << std::endl;
            return;
        }
    }
    std::vector<sf::Texture> object_textures(7);
    for (int i = 0; i < 7; ++i) {
        std::string filename = "bonus/assets/res_" + std::to_string(i + 1) + ".png";
        if (!object_textures[i].loadFromFile(filename)) {
            std::cerr << "Error loading object texture: " << filename << std::endl;
            return;
        }
    }
    std::vector<sf::Texture> map_texture(gameData.mapSize.x * gameData.mapSize.y);
    for (int i = 0; i < gameData.mapSize.x; ++i) {
        for (int j = 0; j < gameData.mapSize.y; ++j) {
            if (!map_texture[i * gameData.mapSize.y + j].loadFromFile("bonus/assets/floor.png")) {
                std::cerr << "Error loading map texture" << std::endl;
                return;
            }
        }
    }
    if (window.isOpen()) {
        window.clear();
        double cell_size = std::min(window.getSize().x / gameData.mapSize.x, window.getSize().y / gameData.mapSize.y);
        double offset_x = (window.getSize().x - (cell_size * gameData.mapSize.x)) / 2;
        double offset_y = (window.getSize().y - (cell_size * gameData.mapSize.y)) / 2;
        double scale = 0.15f;
        std::pair<double, double> object_positions[7] = {{0.25, 0.25}, {0.50, 0.25}, {0.75, 0.25}, {0.25, 0.75}, {0.50, 0.75}, {0.75, 0.75}, {0.25, 0.50}};
        for (int i = 0; i < gameData.mapSize.x; ++i) {
            for (int j = 0; j < gameData.mapSize.y; ++j) {
                sf::Sprite sprite(map_texture[i * gameData.mapSize.y + j]);
                sprite.setScale(cell_size / sprite.getLocalBounds().height, cell_size / sprite.getLocalBounds().height);
                sprite.setPosition(offset_x + i * cell_size, offset_y + j * cell_size);
                window.draw(sprite);
                for (int k = 0; k < 7; ++k) {
                    if (gameData.objectPos[j][i][k] > 0) {
                        sf::Sprite object_sprite(object_textures[k]);
                        float object_scale = cell_size / object_sprite.getLocalBounds().height * scale;
                        object_sprite.setScale(object_scale, object_scale);
                        double object_offset_x = object_positions[k].first * cell_size - (object_scale * object_sprite.getLocalBounds().width) / 2;
                        double object_offset_y = object_positions[k].second * cell_size - (object_scale * object_sprite.getLocalBounds().height) / 2;
                        object_sprite.setPosition(offset_x + i * cell_size + object_offset_x, offset_y + j * cell_size + object_offset_y);
                        window.draw(object_sprite);
                    }
                }
            }
        }
        for (int i = 0; i < gameData.eggList.size(); ++i) {
            sf::Sprite sprite(egg_textures[i]);
            float egg_scale = cell_size / sprite.getLocalBounds().height * scale;
            sprite.setScale(egg_scale, egg_scale);
            double egg_offset_x = 0.75 * cell_size - (egg_scale * sprite.getLocalBounds().width) / 2;
            double egg_offset_y = 0.5 * cell_size - (egg_scale * sprite.getLocalBounds().height) / 2;
            sprite.setPosition(offset_x + gameData.eggList[i].pos.x * cell_size + egg_offset_x, offset_y + gameData.eggList[i].pos.y * cell_size + egg_offset_y);
            window.draw(sprite);
        }
        this->player->render(gameData);
        window.display();
    }
}
