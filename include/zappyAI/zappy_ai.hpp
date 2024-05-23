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
    #include <regex>

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096

namespace Ai
{
    class EngineAi {
        public:
            EngineAi() = default;
            ~EngineAi() = default;
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
            void handleNewMessage();
            void getArgs(int argc, const char **argv);
            void checkNewMessage(std::string reply_data);
            void sendCmdToServer(char *cmd, int nb_byte);
            std::string getNextArg(int argc, const char **argv, int i);
            bool charIsInStr(char c, const std::string &strToAnalyze);
            int getInt(const std::string &str);

            void launchAi();
            void displayHelp();
            void getPort(int argc, const char **argv, int index);
            void analyseIP(int argc, const char **argv, int index);
            void getTeamName(int argc, const char **argv, int index);

            bool isValidIPv4(const std::string &str);
            bool isValidIPv6(const std::string &str);
            bool isValidIP(const std::string &str);

        private:
            int fd = 0;
            int maxFd = 0;
            fd_set readSet;
            fd_set writeSet;
            struct sockaddr_in serverAddress;
            std::string cmdBuffer = "";

            std::string ip = "";
            unsigned short port = 0;
            std::string nameTeam = "";

            EngineAi engineAi;
    };
}


#endif /* !ZAPPYAI_H_ */
