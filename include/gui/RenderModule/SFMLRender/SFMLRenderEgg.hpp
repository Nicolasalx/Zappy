/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLRenderEgg
*/

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameData.hpp"

namespace Gui
{
    class SFMLRenderEgg
    {
        public:
            SFMLRenderEgg(const GameData& gameData);
            void render(const Gui::GameData &gameData);
        private:
            sf::Sprite sprite;
            std::vector<sf::Texture> textures;
            sf::RenderWindow window;
    };
}