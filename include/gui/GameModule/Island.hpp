/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Island
*/

#ifndef ISLAND_HPP_
    #define ISLAND_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Island
    {
        public:
            Island(std::shared_ptr<Gui::GameData> gameData);
            ~Island() = default;

            void update(const Gui::Event &event);

        private:
            std::shared_ptr<Gui::GameData> _gameData;
    
    };
}

#endif /* !ISLAND_H_ */
