/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLRenderObject
*/

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameData.hpp"
#include "TexturePool.hpp"

namespace Gui
{
    class SFMLRenderObject : Gui::TexturePool
    {
        public:
            SFMLRenderObject();
            void LoadObjectTexture(void);
            void render(const Gui::GameData &gameData);
        private:
            sf::Sprite sprite;
            sf::RenderWindow window;
    };
}