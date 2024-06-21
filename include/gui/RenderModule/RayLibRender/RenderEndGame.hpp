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

        void render(const GameData &gameData) override;

        static bool _isEndGame;
        static bool _isGameFinished;

        float x;
        float y;
        float z;
        float _timer = 0;
    };
}

#endif /* !RENDERENDGAME_H_ */