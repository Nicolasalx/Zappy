/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLRenderMap
*/

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameData.hpp"

namespace Gui
{
    class SFMLRenderMap
    {
        public:
            SFMLRenderMap();
            void LoadMapTexture(const GameData &gameData);
            void render(const Gui::GameData &gameData);
        private:
            sf::Sprite sprite;
            std::vector<sf::Texture> textures;
            sf::RenderWindow window;
    };
}