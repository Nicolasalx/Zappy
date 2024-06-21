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

            void clientNumReply(const std::string &args);
            void mapSizeReply(const std::string &args);
            void forwardReply(const std::string &args);
            void rightReply(const std::string &args);
            void leftReply(const std::string &args);
            void lookReply(const std::string &args);
            void inventoryReply(std::string args);
            void broadcastReply(const std::string &args);
            void connectNbrReply(const std::string &args);
            void forkReply(const std::string &args);
            void ejectReply(const std::string &args);
            void takeReply(const std::string &args);
            void setReply(const std::string &args);
            void incantationReply(const std::string &args);
            std::shared_ptr<std::queue<Gui::PlayerCmd>> getSendedMessage();

            void parse_server_reply(const std::string &reply_data);
            void update(std::vector<std::string> &messRecv);

        private:
            std::shared_ptr<std::queue<Gui::PlayerCmd>> _sendedMessage;
            std::shared_ptr<GameData> _gameData;
            std::map<Gui::PlayerCmd, std::function<void(std::string)>> _replyHandler;
    };
}

#endif /* !PLAYERPARSER_H_ */
