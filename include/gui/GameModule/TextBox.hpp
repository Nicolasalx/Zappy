/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
    #define TEXTBOX_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class TextBox
    {
        public:
            TextBox();
            ~TextBox();

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event);

        private:
    
    };
}

#endif /* !TEXTBOX_H_ */
