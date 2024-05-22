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

enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

struct pos_t {
    int x;
    int y;
};

struct player_t {
    int n;
    pos_t pos;
    int level;
    int orientation;
    std::string team_name;
    std::vector<int> inventory;
};

class GameState {
    public:
        GameState();
        ~GameState();
        void parse_server_reply(std::string reply_data);
        void msz(std::vector<std::string> args);
        void bct(std::vector<std::string> args);
        void tna(std::vector<std::string> args);
        void pnw(std::vector<std::string> args);
        void ppo(std::vector<std::string> args);
        void plv(std::vector<std::string> args);
        void pin(std::vector<std::string> args);
        void pdi(std::vector<std::string> args);
        void sgt(std::vector<std::string> args);
    private:
        pos_t map_size;
        int time_unit = 0;
        std::map<std::string, std::function<void(std::vector<std::string>)>> cmd_map;
        std::vector<std::vector<pos_t>> object_pos;
        std::vector<player_t> players_list;
        std::vector<std::string> team_names;
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
};

#endif /* !MYTEAMS_CLIENT_H_ */
