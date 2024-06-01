/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <thread>
    #include <signal.h>
    #include <map>
    #include <iostream>
    #include "my_tracked_exception.hpp"
    #include <memory>
    #include "gameState.hpp"

namespace Gui
{
    constexpr int MAX_PORT_NB = 65535;
    constexpr int BUFFER_SIZE = 4096;
    constexpr int CMD_BUFFER_SIZE = 4096;

    class Client {
        public:
            Client(int argc, const char **argv, std::shared_ptr<GameState> gameState);
            ~Client();

            void init_client_set();
            void monitor_input();
            void handle_new_input();
            void handle_new_message();
            void get_args(int argc, const char **argv);
            void check_new_message(std::string reply_data);
            void send_cmd_to_server(char *cmd, int nb_byte);

        private:
            void create_client();
            void launch_client();

            int fd = 0;
            int max_fd = 0;
            fd_set read_set;
            fd_set write_set;
            unsigned short port = 0;
            struct sockaddr_in server_address;
            std::string cmd_buffer;
            std::string ip;
            
            std::shared_ptr<Gui::GameState> _gameState;
    };
}

#endif /* !CLIENT_H_ */
