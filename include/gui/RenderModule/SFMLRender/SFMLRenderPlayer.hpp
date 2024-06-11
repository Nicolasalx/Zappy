/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderPlayer
*/

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameData.hpp"
#include "SFMLPool.hpp"

namespace Gui
{
    class SFMLRenderPlayer : Gui::SFMLPool
    {
        public:
            SFMLRenderPlayer();
            void render(const Gui::GameData &gameData, sf::RenderWindow &window);
        private:
            sf::Sprite sprite;
    };
}