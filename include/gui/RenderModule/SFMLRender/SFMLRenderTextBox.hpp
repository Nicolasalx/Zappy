/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** textBox
*/

#ifndef RENDERTEXTBOX_H_
    #define RENDERTEXTBOX_H_

    #include "GameData.hpp"
    #include "SFML/Graphics.hpp"
    #include <complex>
    #include <vector>
    #include <memory>

namespace Gui
{
    class SFMLRenderTextBox {
        public:
            SFMLRenderTextBox(TextBoxData boxInfo);
            ~SFMLRenderTextBox() = default;
            void openClose();
            bool isClosed();
            void resize(int window_width, int window_height);
            void addText(sf::RenderWindow &window, const std::string &text, float ypos, const sf::Font &font);
            void draw(sf::RenderWindow &window, const sf::Font &font);
            TextBoxData _boxInfo;
            // Rectangle _box;
            // Rectangle _button;
            // Color _color;
            sf::FloatRect _box;
            sf::FloatRect _button;
            sf::Color _color;
    };

    class SFMLRenderTextBoxList {
        public:
            SFMLRenderTextBoxList() = default;
            ~SFMLRenderTextBoxList() = default;
            void updateTextBoxs(const GameData &gameData);
            void drawAllTextBoxs(sf::RenderWindow &window, const sf::Font &font, const GameData &gameData);
            void renderButtonNextDisp(sf::RenderWindow &window, const sf::Font &font, const GameData &gameData);
            std::vector<SFMLRenderTextBox> _textBoxs;
            bool _changeDisplayLib = false;
    };
}

#endif