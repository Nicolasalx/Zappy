/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include "commandType.hpp"
    #include "getCommand.hpp"
    #include "postCommand.hpp"
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

namespace Ai
{
    class Client;
    class Player;

    class GetCommand
    {
        public:
            void parseServerReply(Ai::Client &client, const std::string &reply_data, Ai::Player &player);
            void parseInventory(Ai::Client &client, const std::string &reply_data, Ai::Player &player);
            std::string extractContentBetweenBrackets(const std::string &input);
            void extractItemInventory(const std::string &itemStr, Ai::Player &player);
            void parseTeam(Client &client, const std::string &reply_data, Ai::Player &player);
            void parseNbSlotsUnused(Client &client, const std::string &reply_data, Ai::Player &player);
            bool checkBasicEvent(const std::string &replyData);
            bool checkMessage(const std::string &replyData);
            bool checkEjection(const std::string &replyData);
            void parseLook(Client &client, const std::string &reply_data, Ai::Player &player);

        private:
    };

    class PostCommand
    {
        public:
            void broadcastText(Client &client, const std::string &text);
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

    class Client {
        public:
            Client(int argc, const char **argv);
            ~Client();
            void createClient();
            void initClientSet();
            void launchClient();
            void monitorInput();
            void handleNewInput();
            void handleNewMessage(Ai::Player &player);
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
            std::list<Ai::CommandType> getQueue();
            void setQueue(const std::list<Ai::CommandType> &queue);

            void insertInQueue(Ai::CommandType commandType);

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
            std::list<Ai::CommandType> _queueCommand;
            bool _cmdCanBeSend = true;
    };
}

#endif /* !POSTCOMMAND_H_ */
