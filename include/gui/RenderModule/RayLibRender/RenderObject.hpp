/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** object
*/

#ifndef RENDEROBJECT_H_
    #define RENDEROBJECT_H_

    #include "ARayLibModel.hpp"
    #include "GameConfig.hpp"
    #include "GameData.hpp"
    #include <complex>
    #include <vector>
    #include <memory>

namespace Gui
{
    class RenderObject: public virtual ARayLibModel
    {
        public:
            RenderObject();
            ~RenderObject() = default;

            void render(const GameData &gameData) override;

            std::array<std::array<float, 7>, 2> object_padding;
    };
}

#endif /* !RENDEROBJECT_H_ */
