/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

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

#endif /* !WINDOW_H_ */
