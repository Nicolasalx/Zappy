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
    struct SizeWindow {
        float width;
        float height;
    };

    class RenderWindow
    {
        public:
            RenderWindow();
            ~RenderWindow();

            static SizeWindow sizeWindow;

            static SizeWindow getWindowSize()
            {
                return sizeWindow;
            }

        private:
    };
}

#endif /* !RENDERWINDOW_H_ */
