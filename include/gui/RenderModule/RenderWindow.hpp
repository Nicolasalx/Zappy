/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** window
*/

#ifndef RENDERWINDOW_H_
    #define RENDERWINDOW_H_

namespace Gui
{
    class RenderWindow
    {
        public:
            RenderWindow();
            ~RenderWindow() = default;

            int window_width = WINDOW_WIDTH;
            int window_height = WINDOW_HEIGHT;

        private:
    };
}

#endif /* !RENDERWINDOW_H_ */
