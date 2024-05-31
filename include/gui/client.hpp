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

    #include "gameState.hpp"

namespace Gui
{
    class Client {
        public:
            Client(int argc, const char **argv);
            ~Client();
            void create_client();
            void init_client_set();
            void launch_client();
            void monitor_input();
            void handle_new_input();
            void handle_new_message();
            void get_args(int argc, const char **argv);
            void check_new_message(std::string reply_data);
            void send_cmd_to_server(char *cmd, int nb_byte);
            void launch_graphic();

        private:
            int fd;
            int max_fd = 0;
            fd_set read_set;
            fd_set write_set;
            unsigned short port;
            struct sockaddr_in server_address;
            std::string cmd_buffer;
            std::string ip;
            GameState gameState;
            std::thread graphic_thread;
    };
}

#endif /* !CLIENT_H_ */
