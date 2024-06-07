/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include "raylibInfo.hpp"
    #include "infoGame.hpp"

namespace Gui
{
    class Window {
        public:
            Window();
            ~Window() = default;
            int window_width = WINDOW_WIDTH;
            int window_height = WINDOW_HEIGHT;
        
        private:

    };
}

#endif /* !WINDOW_H_ */
