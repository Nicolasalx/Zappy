/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** myteams_client
*/

#ifndef MYTEAMS_CLIENT_H_
    #define MYTEAMS_CLIENT_H_

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
    #include <vector>
    #include <map>
    #include <functional>

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096

class GameState {
    public:
        GameState();
        ~GameState();
        void parse_server_reply(std::string reply_data);
        void msz(std::vector<std::string> args);
    private:
        int width = 0;
        int height = 0;
        std::map<std::string, std::function<void(std::vector<std::string>)>> cmd_map;
        std::vector<std::vector<int>> map;
};

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
        void send_cmd_to_server(char *cmd, int nb_byte);
        void handle_server_reply(char *reply_data);
        void launch_graphic();
    private:
        int fd;
        int max_fd = 0;
        fd_set read_set;
        fd_set write_set;
        unsigned short port;
        struct sockaddr_in server_address;
        std::string cmd_buffer;
        GameState gameState;
};

#endif /* !MYTEAMS_CLIENT_H_ */
