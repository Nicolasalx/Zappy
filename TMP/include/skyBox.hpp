/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** skyBox
*/

#ifndef SKYBOX_H_
    #define SKYBOX_H_

    #include "infoGame.hpp"

namespace Gui
{
    class SkyBox : public virtual IRaylib {
        public:
            SkyBox(std::shared_ptr<GameState> gameState);
            ~SkyBox() = default;
            void render();
            Model model;

        private:
            std::shared_ptr<GameState> _gameState;

    };
}

#endif /* !SKYBOX_H_ */
