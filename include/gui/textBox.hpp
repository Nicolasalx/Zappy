/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** textBox
*/

#ifndef TEXTBOX_H_
    #define TEXTBOX_H_

    #include <string>
    #include "raylibInfo.hpp"
    #include "infoGame.hpp"

namespace Gui
{
    class TextBox {
        public:
            TextBox(float x, float y, float w, float h, int window_w, int window_h);
            TextBox(float x, float y, float w, float h, int window_w, int window_h, int state);
            ~TextBox() = default;
            void openClose();
            bool isClosed();
            void resize(int window_width, int window_height);
            void addText(std::string text, float ypos);
            void draw();
        private:
            float _x;
            float _y;
            float _width;
            float _height;
            int state;
            int _window_width = WINDOW_WIDTH;
            int _window_height = WINDOW_HEIGHT;
            Rectangle _box;
            Rectangle _button;
            Color _color;
    };
}

#endif /* !TEXTBOX_H_ */
