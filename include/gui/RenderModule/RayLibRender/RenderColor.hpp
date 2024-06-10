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

namespace Gui
{
    enum GameColor {
        WHITE_COLOR,
        BLACK_COLOR,
        BLUE_COLOR,
        GREEN_COLOR,
        RED_COLOR,
        GRAY_COLOR,
        PURPLE_COLOR
    };

    class RenderColor
    {
        public:
            static Color getColorFromGame(GameColor &gameColor);
        private:
            static std::map<GameColor, Color> _colorMap;
    };
}

#endif /* !RENDERCOLOR_H_ */
