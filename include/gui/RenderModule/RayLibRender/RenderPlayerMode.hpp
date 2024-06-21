/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderPlayerMode
*/

#ifndef RENDERPLAYERMODE_H_
    #define RENDERPLAYERMODE_H_

    #include <vector>
    #include <string>
    #include "ARayLibModel.hpp"
    #include <map>

namespace Gui
{
    class RenderPlayerMode: public virtual ARayLibModel
    {
        public:
            RenderPlayerMode() = default;
            ~RenderPlayerMode() = default;

            void render(const GameData &gameData) override;

        private:
    };
}

#endif /* !RENDERPLAYER_H_ */
