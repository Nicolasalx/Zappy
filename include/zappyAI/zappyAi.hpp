/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy_ai
*/

#ifndef ZAPPYAI_H_
    #define ZAPPYAI_H_

    #include "my_tracked_exception.hpp"
    #include "my_log.hpp"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <unistd.h>
    #include <iostream>
    #include <string>
    #include <memory>
    #include <csignal>
    #include <vector>
    #include <map>
    #include <functional>
    #include <thread>
    #include <limits.h>
    #include <stdlib.h>
    #include <cstring>
    #include <list>
    #include <regex>
    #include <string>

    #include "client.hpp"
    #include "postCommand.hpp"
    #include "tile.hpp"
    #include "inventory.hpp"
    #include "item.hpp"
    #include "dimensionWorld.hpp"
    #include "message.hpp"

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096

namespace Ai
{
    class Player
    {
        public:
            Player(const Client& client) : _client(client) {}
            void engineAI(Client &client);
            void setElemToInventory(Item item, int nbElem);
            void setDataTeam(int nbSlots, int xAxis, int yAxis);
            void setNbUnusedSlots(int nbSlots);
            void sendCommand(const CommandType &commandType);
            void sendCommand(const CommandType &commandType, const std::string &text);
            void nextInstructionAi(Client &client);
            void setMap(std::vector<Tile> listTile);
            void setRefreshInventory(bool refresh);
            void setRefreshLook(bool refresh);
            void setNewMessage(const Message &message);
            void setNewLevel(int level);

        private:
            PostCommand postCmd;
            bool _refreshInventory = false;
            bool _refreshLook = false;
            int _nbSlotsTeam = 0;
            int _nbTeamUnusedSlots = 0;
            DimensionWorld dimensionWorld;
            bool _clientHasaTeam = false;
            Client _client;

            Inventory inventory;
            std::vector<Tile> _contentLook;
            std::vector<Message> _listMessage;
            int _level = 0;
    };
}

#endif /* !ZAPPYAI_H_ */
