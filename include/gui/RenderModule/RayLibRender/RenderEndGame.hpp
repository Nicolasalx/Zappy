/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** End game
*/

#ifndef RENDERENDGAME_H_
    #define RENDERENDGAME_H_

    #include "ARayLibModel.hpp"
    #include "GameData.hpp"
    #include "GameConfig.hpp"
    #include <vector>
    #include <memory>

namespace Gui
{
    class RenderEndGame : public virtual ARayLibModel
    {
    public:
        RenderEndGame();
        ~RenderEndGame() = default;

        void render(const GameData &gameData);

        private:
            bool _isEndGame = false;
    };
}

#endif /* !RENDERENDGAME_H_ */