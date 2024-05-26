/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** tile
*/

#ifndef TILE_H_
    #define TILE_H_

    #include "inventory.hpp"

namespace Ai
{
    struct Tile {
        Inventory elements;
        int player = 0;
    };
}

#endif /* !TILE_H_ */
