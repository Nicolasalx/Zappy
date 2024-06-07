/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#ifndef RENDEREGG_H_
    #define RENDEREGG_H_

    #include "ARayLibModel.hpp"
    #include "gameState.hpp"
    #include "infoGame.hpp"
    #include <vector>
    #include <memory>
    #include "raylibInfo.hpp"

namespace Gui
{
    class RenderEgg : public virtual Gui::ARayLibModel
    {
    public:
        RenderEgg(const std::string &eggModel, const std::string &eggTexture);
        ~RenderEgg() = default;

        void render(std::shared_ptr<Gui::GameState> gameState);
    };
}

#endif /* !RENDEREGG_H_ */