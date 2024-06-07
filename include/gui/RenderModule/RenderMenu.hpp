/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderMenu
*/

#ifndef RENDERMENU_H_
    #define RENDERMENU_H_

    #include "GameData.hpp"

namespace Gui {
    class RenderMenu
    {
        public:
            RenderMenu();
            ~RenderMenu() = default;
            void render(const GameData &gameData);

        private:
    };
}

#endif /* !RENDERMENU_H_ */
