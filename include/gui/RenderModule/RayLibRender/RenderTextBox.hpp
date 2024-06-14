/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** textBox
*/

#ifndef RENDERTEXTBOX_H_
    #define RENDERTEXTBOX_H_

    #include "ARayLibModel.hpp"
    #include "GameConfig.hpp"
    #include "GameData.hpp"
    #include <complex>
    #include <vector>
    #include <memory>

namespace Gui
{
    class RenderTextBox {
        public:
            RenderTextBox(TextBoxData boxInfo);
            ~RenderTextBox() = default;
            void openClose();
            bool isClosed();
            void resize(int window_width, int window_height);
            void addText(std::string text, float ypos);
            void draw();

            TextBoxData _boxInfo;
            Rectangle _box;
            Rectangle _button;
            Color _color;
    };

    class RenderTextBoxList {
        public:
            RenderTextBoxList() = default;
            ~RenderTextBoxList() = default;
            void updateTextBoxs(const GameData &gameData);
            void render(const GameData &gameData);

            std::vector<Gui::RenderTextBox> _textBoxs;
    };
}

#endif