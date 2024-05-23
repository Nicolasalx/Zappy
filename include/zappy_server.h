/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** myteams_server
*/

#ifndef MYTEAMS_SERVER_H_
    #define MYTEAMS_SERVER_H_

    #include "my_importall.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <string.h>
    #include <stdlib.h>

    #define MAX_CLIENT FD_SETSIZE
    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CLIENT_BUFFER_SIZE 4096
    #define CWD_SIZE 4096
    #define MAX_TEAM_NB 100

    #define MAX_TEAMNAME_SIZE 32
    #define MAX_WAITING_CMD 10

    #define NEW_CLIENT_MESSAGE "WELCOME\n"

    #define RESOURCE_RESPAWN_FREQ 20.0

typedef enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NB_ITEM
} item_t;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    NB_ORIENTATION
} orientation_t;

typedef struct {
    int item[NB_ITEM];
} tile_t;

typedef struct {
    int size_x;
    int size_y;
    tile_t **map;
} world_t;

typedef struct {
    char name[MAX_TEAMNAME_SIZE + 1];
    int remaining_place;
} team_t;

typedef struct {
    int id;
    int pos_x;
    int pos_y;
    int orientation[NB_ORIENTATION];
    int level;
    int inventory[NB_ITEM];
    int food_time_unit;
    team_t *team;
} player_t;

typedef struct {
    int fd;
    bool is_graphic;
    node_t *waiting_cmd;
    player_t player;
} client_t;

typedef struct {
    int port;
    double freq;
    int fd;
    int team_count;
    int client_nb;
    bool is_immortal;
    int player_count;
    struct timeval last_update;
    struct timeval last_resource_spawn;
    struct sockaddr_in address;
    fd_set read_set;
    fd_set write_set;
    client_t clients[MAX_CLIENT];
    world_t world;
    team_t team_list[MAX_TEAM_NB];
} server_t;

typedef struct {
    char *name;
    int nb_arg;
    void (*method)(int, char **, client_t *, server_t *);
} gui_handler_t;

typedef struct {
    char *name;
    bool has_arg;
    void (*method)(char *, client_t *, server_t *);
} ai_handler_t;

extern const gui_handler_t gui_cmd_handler[];
extern const ai_handler_t ai_cmd_handler[];

extern double resource_density[NB_ITEM];

void get_args(int argc, const char **argv, server_t *server);
void create_server(server_t *server);
void init_server_set(server_t *server, int *max_fd);
void monitor_client(server_t *server, int max_fd);
void handle_new_connection(server_t *server);
void lauch_server(server_t *server);
void delete_server(server_t *server);
server_t *get_server(server_t *server);

void add_client(server_t *server, client_t *client);
void remove_client(client_t *client);
void get_client_input(server_t *server, client_t *client);
void handle_client_input(server_t *server, client_t *client, char *cmd);
void send_msg_client(int fd, char *reply);
void handle_new_player(server_t *, client_t *new_client);
void handle_gui_input(server_t *server, client_t *client, char *cmd);
void handle_ai_input(server_t *server, client_t *client, char *cmd);

// args management
void get_port_and_freq(const char **argv, server_t *server, int argc, const char **args);
void get_map_size(const char **argv, server_t *server, int argc, const char **args);
void get_clients_nb(const char **argv, server_t *server, int argc, const char **args);
void get_teams_name(const char **argv, server_t *server, int i, int argc);
void check_arg_validity(server_t *server);

// gui command
void msz_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void sgt_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void sst_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void sgt_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void tna_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void plv_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void ppo_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void mct_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void bct_cmd(int nb_args, char **argv, client_t *client, server_t *server);

// ai command
void inventory_cmd(char *arg, client_t *client, server_t *server);

// game
void init_player(client_t *client, server_t *server);
void update_simulation(server_t *server);
void create_world(server_t *server);
void spawn_resource(server_t *server);
void update_resource(server_t *server);
void consume_food(server_t *server);

#endif /* !MYTEAMS_SERVER_H_ */
