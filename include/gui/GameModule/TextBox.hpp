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
            TextBox(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client);
            ~TextBox() = default;

            void addText(TextBoxData &textBox, size_t index, std::string text);
            void update(const Gui::Event &event);
            void resize(int windowWidth, int windowHeight);
            void resizeSlideBar(int windowWidth, int windowHeight);
            void openClose(const Gui::Event &event);
            bool isClosed(TextBoxData &_text);
            void updateServerResp();
            void updateBroadcastResp();
            void updateGeneralInfo();
            void updateListPlayerLevel();
            void updateOnePlayerInfo();
            void updateOneTileInfo();
            void initSlideBar();
            void updateSlideBar(const Gui::Event &events);

        private:
            std::shared_ptr<Gui::GameData> _gameData;
            std::shared_ptr<Gui::IClient> _client;
            std::vector<int> listLevelPlayer;
    };
}

#endif /* !TEXTBOX_H_ */
