/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** PlayerParser
*/

#ifndef PLAYERPARSER_HPP_
    #define PLAYERPARSER_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include <map>
    #include <functional>
    #include "GameData.hpp"
    #include "Event.hpp"
    #include <queue>

namespace Gui
{
    enum class PlayerCmd
    {
        WELCOME,
        CLIENT_NUM,
        MAP_SIZE,
        FORWARD,
        RIGHT,
        LEFT,
        LOOK,
        INVENTORY,
        BROADCAST,
        CONNECT_NBR,
        FORK,
        EJECT,
        TAKE,
        SET,
        INCANTATION,
        NB_ACTION
    };

    class PlayerParser
    {
        public:
            PlayerParser(std::shared_ptr<GameData> gameData);
            ~PlayerParser() = default;

            void clientNumReply(std::string args);
            void mapSizeReply(std::string args);
            void forwardReply(std::string args);
            void rightReply(std::string args);
            void leftReply(std::string args);
            void lookReply(std::string args);
            void inventoryReply(std::string args);
            void broadcastReply(std::string args);
            void connectNbrReply(std::string args);
            void forkReply(std::string args);
            void ejectReply(std::string args);
            void takeReply(std::string args);
            void setReply(std::string args);
            void incantationReply(std::string args);
            std::shared_ptr<std::queue<Gui::PlayerCmd>> getSendedMessage();

            void parse_server_reply(std::string reply_data);
            void update(std::vector<std::string> &messRecv);

        private:
            std::shared_ptr<std::queue<Gui::PlayerCmd>> _sendedMessage;
            std::shared_ptr<GameData> _gameData;
            std::map<Gui::PlayerCmd, std::function<void(std::string)>> _replyHandler;
    };
}

#endif /* !PLAYERPARSER_H_ */
