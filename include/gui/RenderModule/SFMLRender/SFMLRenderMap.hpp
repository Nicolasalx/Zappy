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
#include "TexturePool.hpp"

namespace Gui
{
    class SFMLRenderMap : Gui::TexturePool
    {
        public:
            SFMLRenderMap();
            void render(const Gui::GameData &gameData, sf::RenderWindow &window);
        private:
            sf::Sprite sprite;
    };
}