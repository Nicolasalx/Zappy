/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** PlayerMode
*/

#ifndef PLAYERMODE_HPP_
    #define PLAYERMODE_HPP_

    #include "GameData.hpp"
    #include "Event.hpp"
    #include "InfoGame.hpp"
    #include <memory>
    #include "IClient.hpp"

namespace Gui
{
    class PlayerMode
    {
        public:
            PlayerMode(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client);
            ~PlayerMode() = default;

            void addButtonPlayerMode(const std::string &contentText, Pos pos, const SizeButton &sizeButton, ActionButtonPlayer actPlayer);
            void turnLeft();
            void initButtonPlayerMode();
            void resize(const Gui::Event &event);
            void update(const Gui::Event &event);

            void turnLeft();
        private:
            std::shared_ptr<Gui::GameData> _gameData;
            std::shared_ptr<Gui::IClient> _client;

    };
}

#endif /* !PLAYER_H_ */
