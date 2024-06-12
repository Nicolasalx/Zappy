/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
    #define TEXTBOX_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class TextBox
    {
        public:
            TextBox(std::shared_ptr<Gui::GameData> gameData);
            ~TextBox() = default;

            void addText(TextBoxData &textBox, size_t index, std::string text);
            void update(const Gui::Event &event);
            void resize(int window_width, int window_height);
            void openClose(const Gui::Event &event);
            bool isClosed(TextBoxData &_text);
            void updateServerResp();
            void updateGeneralInfo();
            void updateListPlayerLevel();

        private:
            std::shared_ptr<Gui::GameData> _gameData;
            std::vector<int> listLevelPlayer;
            
    };
}

#endif /* !TEXTBOX_H_ */
