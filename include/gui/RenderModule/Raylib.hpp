/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef RAYLIB_H_
    #define RAYLIB_H_

    #include "ARenderModule.hpp"
    #include <raylib.h>
    #include <iostream>

namespace Gui {

    class Raylib : public ARenderModule
    {
        public:
            Raylib();
            ~Raylib() override;
 
            Gui::Event getEvent() override;
            void render(const Gui::GameData &gameData) override;

        private:
    };
}

#endif /* !RAYLIB_H_ */
