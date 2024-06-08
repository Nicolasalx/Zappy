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

            void update(const Gui::Event &event);

        private:
            std::shared_ptr<Gui::GameData> _gameData;

    };
}

#endif /* !TEXTBOX_H_ */
