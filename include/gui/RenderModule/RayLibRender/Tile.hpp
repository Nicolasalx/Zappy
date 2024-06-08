/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** TextBox
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include "Raylib.hpp"

namespace Gui {
    class Tile
    {
        public:
            Tile();
            ~Tile() override;

            void render(const GameData &gameData);

        private:
    
    };
}

#endif /* !TILE_H_ */