/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** TexturePool
*/

#ifndef TEXTUREPOOL_HPP_
    #define TEXTUREPOOL_HPP_

    #include <string>
    #include <map>
    #include <SFML/Graphics.hpp>

namespace Gui
{
    class TexturePool
    {
    private:
        std::map<std::string, sf::Texture> texture;

    public:
        TexturePool() = default;
        ~TexturePool() = default;

        const sf::Texture &getTexture(const std::string &path);
    };
}

#endif /* !TEXTUREPOOL_HPP_ */
