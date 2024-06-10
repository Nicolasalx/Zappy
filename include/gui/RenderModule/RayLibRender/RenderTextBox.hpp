/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** textBox
*/

#ifndef RENDERTEXTBOX_H_
    #define RENDERTEXTBOX_H_

namespace Gui
{
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
            void drawAllTextBoxs(ray_info_t &rayInfo);
            void resize(int window_width, int window_height);

            std::vector<int> listLevelPlayer;
            std::vector<Gui::TextBox> _textBoxs;
            std::shared_ptr<GameState> _gameState;
    };
}

#endif