/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** RenderColor
*/

#ifndef RENDERCOLOR_H_
    #define RENDERCOLOR_H_

    #include <raylib.h>
    #include <map>
    #include "InfoGame.hpp"

namespace Gui
{
    class RenderColor
    {
        public:
            static Color getColorFromGame(const GameColor &gameColor);
        private:
            static std::map<GameColor, Color> _colorMap;
    };
}

#endif /* !RENDERCOLOR_H_ */
