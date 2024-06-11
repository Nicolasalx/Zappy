/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLRenderEgg
*/

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameData.hpp"
#include "TexturePool.hpp"

namespace Gui
{
    class SFMLRenderEgg : Gui::TexturePool
    {
    public:
        SFMLRenderEgg();
        void LoadEggTexture(const GameData &gameData);
        void render(const Gui::GameData &gameData);

    private:
        sf::Sprite sprite;
        sf::RenderWindow window;
    };
}
