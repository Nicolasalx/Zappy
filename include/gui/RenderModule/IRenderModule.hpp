/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** IRendermodule
*/

#ifndef IRENDERMODULE_H_
    #define IRENDERMODULE_H_

    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class IRenderModule
    {
        public:
            virtual ~IRenderModule() = default;
            virtual Event getEvent() = 0;
            virtual void render(const Gui::Gamedata &gameData) = 0;
    };
}

#endif /* !IRENDERMODULE_H_ */
