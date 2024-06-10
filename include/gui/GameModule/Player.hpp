/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"
    #include <map>

namespace Gui
{
    class Player
    {
        public:
            Player(std::shared_ptr<Gui::GameData> gameData);
            ~Player() = default;

            void update(const Gui::Event &event);
            void updateAnimation(PlayerData &player);
            void updatePlayerPos(PlayerData &player);
        private:
            std::shared_ptr<Gui::GameData> _gameData;
            std::map<int, int> playerOrientation;
    };
}

#endif /* !PLAYER_H_ */
