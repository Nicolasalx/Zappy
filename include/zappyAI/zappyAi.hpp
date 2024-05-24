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

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096

namespace Ai
{
    enum CommandType {
        TEAM,
        FORWARD,
        RIGHT,
        LEFT,
        LOOK,
        INVENTORY,
        BROADCAST_TEXT,
        CONNECT_NBR,
        FORK,
        EJECT,
        TAKE_OBJECT,
        SET_OBJECT,
        INCANTATION
    };

    typedef enum {
        FOOD,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME
    } Item;

    class Client;

    class PostCommand
    {
        public:
            void broadcastText(Client &client);
            void connectNbr(Client &client);
            void eject(Client &client);
            void fork(Client &client);
            void forward(Client &client);
            void incantation(Client &client);
            void inventory(Client &client);
            void left(Client &client);
            void right(Client &client);
            void setObject(Client &client);
            void takeObject(Client &client);
            void look(Client &client);
            void linkTeam(Ai::Client &client);

        private:
    };

    struct Inventory {
        int food = 0;
        int linemate = 0;
        int deraumere = 0;
        int sibur = 0;
        int mendiane = 0;
        int phiras = 0;
        int thystame = 0;
    };

    class Player
    {
        public:
            void engineAI(Client &client);

            void setElemToInventory(Item item, int nbElem);
            void setPlayerTeam();

        private:
            PostCommand postCmd;

            Inventory inventory;
            int nbSlotsTeam = 0;
            bool _clientHasaTeam = false;
    };

    class GetCommand
    {
        public:
            void parseServerReply(Client &client, const std::string &reply_data, Player &player);
            void parseResponseFormat();
            void parseInventory(const std::string &reply_data, Player &player);
            std::string extractContentBetweenBrackets(const std::string &input);
            void extractItemInventory(const std::string &itemStr, Player &player);

        private:
    };

    class Client {
        public:
            Client(int argc, const char **argv);
            ~Client();
            void createClient();
            void initClientSet();
            void launchClient();
            void monitorInput();
            void handleNewInput();
            void handleNewMessage(Player &player);
            void getArgs(int argc, const char **argv);
            void checkNewMessage(Player &player, const std::string &reply_data);
            void sendCmdToServer(char *cmd, int nb_byte);
            std::string getNextArg(int argc, const char **argv, int i);
            static bool charIsInStr(char c, const std::string &strToAnalyze);
            static int getInt(const std::string &str);
            bool isConnected();

            void displayHelp();
            void getPort(int argc, const char **argv, int index);
            void analyseIP(int argc, const char **argv, int index);
            void getTeamNameParsing(int argc, const char **argv, int index);

            bool isValidIPv4(const std::string &str);
            bool isValidIPv6(const std::string &str);
            bool isValidIP(const std::string &str);

            std::string getTeamName();
            std::list<CommandType> getQueue();
            void setQueue(const std::list<Ai::CommandType> &queue);

            void insertInQueue(CommandType commandType);
            void parseInventory();

            bool canSendCommand();
            void enableSendCommand();
            void disableSendCommand();

        private:
            int fd = 0;
            int maxFd = 0;
            fd_set readSet;
            fd_set writeSet;
            struct sockaddr_in serverAddress;
            std::string cmdBuffer = "";

            bool _isConnected = false;

            std::string ip = "";
            unsigned short port = 0;
            std::string teamName = "";

            PostCommand postCmd;
            GetCommand getCmd;

            std::list<CommandType> _queueCommand;
            bool _cmdCanBeSend = true;
    };
}

#endif /* !ZAPPYAI_H_ */
