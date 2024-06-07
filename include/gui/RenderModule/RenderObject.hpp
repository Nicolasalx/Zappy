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
    class RenderObject : public virtual ARayLibModel
    {
        public:
            RenderObject();
            ~RenderObject() = default;

            void render(const GameData &gameData);

            float object_padding[7][2];

        private:

    };
}

#endif /* !RENDEROBJECT_H_ */
