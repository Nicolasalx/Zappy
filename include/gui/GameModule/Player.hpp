/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Player
    {
        public:
            Player();
            ~Player();

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event);

        private:
    
    };
}

#endif /* !PLAYER_H_ */
