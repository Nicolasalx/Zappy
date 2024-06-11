/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLPool
*/

#ifndef SFMLPOOL_HPP_
    #define SFMLPOOL_HPP_

    #include <string>
    #include <map>
    #include <SFML/Graphics.hpp>

namespace Gui
{
    class SFMLPool
    {
    private:
        std::map<std::string, sf::Texture> texture;

    public:
        SFMLPool() = default;
        ~SFMLPool() = default;

        const sf::Texture &getTexture(const std::string &path);
    };
}

#endif /* !SFMLPOOL_HPP_ */
