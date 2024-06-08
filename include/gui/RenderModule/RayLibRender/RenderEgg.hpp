/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#ifndef RENDEREGG_H_
    #define RENDEREGG_H_

    #include "ARayLibModel.hpp"
    #include "GameData.hpp"
    #include "GameConfig.hpp"
    #include <vector>
    #include <memory>

namespace Gui
{
    class RenderEgg : public virtual ARayLibModel
    {
    public:
        RenderEgg();
        ~RenderEgg() = default;

        void render(const GameData &gameData);
    };
}

#endif /* !RENDEREGG_H_ */