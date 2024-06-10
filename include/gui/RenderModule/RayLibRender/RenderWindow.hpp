/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** window
*/

#ifndef RENDERWINDOW_H_
    #define RENDERWINDOW_H_

    #include "InfoGame.hpp"

namespace Gui
{
    class RenderWindow
    {
        public:
            RenderWindow();
            ~RenderWindow();

            static WindowSize sizeWindow;

            static WindowSize getWindowSize()
            {
                return sizeWindow;
            }

        private:
    };
}

#endif /* !RENDERWINDOW_H_ */
