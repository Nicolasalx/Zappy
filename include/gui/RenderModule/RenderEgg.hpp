/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "GameData.hpp"
    #include "infoGame.hpp"
    #include <vector>
    #include <memory>
    #include "raylibInfo.hpp"

namespace Gui {
    class RenderEgg
    {
        public:
            RenderEgg();
            ~RenderEgg() = default;
            void render(const GameData &gameData);

        private:
    };
}

#endif /* !EGG_H_ */