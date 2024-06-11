/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** TexturePool
*/

#include "TexturePool.hpp"

const sf::Texture &Gui::TexturePool::getTexture(const std::string &path)
{
    sf::Texture newTexture;

    if (!this->texture.contains(path)) {
        if (!newTexture.loadFromFile(path)) {
            throw std::runtime_error("Invalide texture path: " + path + "\n");
        }
        this->texture[path] = newTexture;
    }
    return this->texture.at(path);
}
