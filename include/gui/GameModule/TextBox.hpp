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
            TextBox();
            ~TextBox();

            const Gui::GameData &update(const Gui::Event &event);

        private:
    
    };
}

#endif /* !TEXTBOX_H_ */
