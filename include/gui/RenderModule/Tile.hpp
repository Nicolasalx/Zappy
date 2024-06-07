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

            const Gui::GameData &update(const Gui::Event &event) override;

        private:
    
    };
}

#endif /* !TILE_H_ */