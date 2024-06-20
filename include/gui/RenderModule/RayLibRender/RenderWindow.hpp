/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** window
*/

#ifndef RENDERWINDOW_H_
    #define RENDERWINDOW_H_

    #include "InfoGame.hpp"
    #include <raylib.h>

namespace Gui
{
    class RenderWindow
    {
        public:
            RenderWindow();
            ~RenderWindow();

            Size windowSize;
            bool launched;
            Sound _soundGame;
            Sound _soundEndGame;
        private:
    };
}

#endif /* !RENDERWINDOW_H_ */
