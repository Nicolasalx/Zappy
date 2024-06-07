/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Island
*/

#ifndef ISLAND_HPP_
    #define ISLAND_HPP_

    #include "Zappy.hpp"
    #include "GameData.hpp"

namespace Gui
{
    class Island
    {
        public:
            Island();
            ~Island() = default;

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event);

        private:
    
    };
}

#endif /* !ISLAND_H_ */
