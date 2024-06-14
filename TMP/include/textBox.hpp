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
    struct box_info {
        float x;
        float y;
        float width;
        float height;
        int window_width;
        int window_height;
        float text_size;
        int state;
    };

    class TextBox {
        public:
            TextBox(box_info boxInfo);
            ~TextBox() = default;
            void openClose();
            bool isClosed();
            void resize(int window_width, int window_height);
            void addText(std::string text, float ypos);
            void draw();
        private:
            box_info _boxInfo;
            Rectangle _box;
            Rectangle _button;
            Color _color;
    };

    class TextBox_list {
        public:
            TextBox_list(std::shared_ptr<GameState> gameState, int window_width, int window_height);
            ~TextBox_list() = default;
            void render(ray_info_t &rayInfo);
            void resize(int window_width, int window_height);

            std::vector<int> listLevelPlayer;
            std::vector<Gui::TextBoxData> _textBoxs;
            std::shared_ptr<GameState> _gameState;
    };
}

#endif /* !TEXTBOX_H_ */
