/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** PlayerMode
*/

#ifndef PLAYERMODE_HPP_
    #define PLAYERMODE_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"
    #include <queue>
    #include "PlayerParser.hpp"

namespace Gui
{
    class PlayerMode
    {
        public:
            PlayerMode(std::shared_ptr<Gui::GameData> gameData, std::shared_ptr<Gui::IClient> client);
            ~PlayerMode() = default;

            void addButtonPlayerMode(const std::string &contentText, Pos pos, const SizeButton &sizeButton, std::function<void()> actPlayer);
            void initButtonPlayerMode();
            void resize(const Gui::Event &event);
            void update(const Gui::Event &event);

            void setSendedMessageQueue(std::shared_ptr<std::queue<Gui::PlayerCmd>> messageQueue);

            void turnLeft();
            void turnRight();
            void forward();

            void look();
            void eject();
            void inventory();
            void fork();
            void incantation();
            void takeElement(Elements elements);
            void setElement(Elements elements);

            std::string getNameElementFromEnum(Elements elements);

        private:
            std::shared_ptr<Gui::GameData> _gameData;
            std::shared_ptr<Gui::IClient> _client;
            std::shared_ptr<std::queue<Gui::PlayerCmd>> _messageQueue;
            bool _hasBeenUpdatedMessQueue = false;
            bool _buttonAlreadyClicked = false;
    };
}

#endif /* !PLAYER_H_ */
