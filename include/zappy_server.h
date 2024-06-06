/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy_server
*/

#ifndef ZAPPY_SERVER_H_
    #define ZAPPY_SERVER_H_

    #include "my_importall.h"
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>

    #define MAX_CLIENT FD_SETSIZE
    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CLIENT_BUFFER_SIZE 4096
    #define CWD_SIZE 4096
    #define MAX_TEAM_NB 10
    #define MAX_PLAYER_CONNECTED_PER_TEAM 100
    #define MAX_CLIENT_NB 100
    #define MAX_BROADCAST_LEN 256
    #define MAX_FREQUENCE_NB 150
    #define MAX_WORLD_SIZE 100

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
} orientation_t;

typedef struct {
    int level;
    int nb_players;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} elevation_requirement_t;

typedef struct {
    int item[NB_ITEM];
} tile_t;

typedef struct {
    int size_x;
    int size_y;
    tile_t **map;
} world_t;

typedef struct {
    int pos_x;
    int pos_y;
    int nb;
} egg_t;

typedef struct {
    char name[MAX_TEAMNAME_SIZE + 1];
    int remaining_spot;
    int player_max;
    node_t *egg_list;
} team_t;

typedef struct {
    bool is_graphic;
    int id;
    int pos_x;
    int pos_y;
    int level;
    int inventory[NB_ITEM];
    int food_time_unit;
    orientation_t orientation;
    node_t *incentation_mate;
    bool in_incentation;
    team_t *team;
} player_t;

typedef struct {
    int fd;
    node_t *waiting_cmd;
    player_t player;
    char *cmd_buffer;
    size_t buffer_size;
} client_t;

typedef struct {
    struct timeval timeout;
    struct timeval start;
    struct timeval end;
} serv_timeout_t;

typedef struct {
    double freq;
    bool is_immortal;
    int client_nb;
    bool end_game;
    bool pause_game;
} server_opt;

typedef struct {
    int team_count;
    int player_count;
    int egg_count;
    struct timeval last_update;
    struct timeval last_resource_spawn;
    team_t team_list[MAX_TEAM_NB];
    world_t world;
} game_t;

typedef struct {
    int port;
    int fd;
    struct sockaddr_in address;
    fd_set read_set;
    fd_set write_set;
    client_t clients[MAX_CLIENT];
    server_opt opt;
    serv_timeout_t time;
    game_t game;
} server_t;

typedef struct {
    char *name;
    int nb_arg;
    void (*method)(int, char **, client_t *, server_t *);
} gui_handler_t;

typedef struct {
    void (*method)(char *, client_t *, server_t *);
    char *args;
    int time_to_wait;
} waiting_cmd_t;

typedef struct {
    char *name;
    bool has_arg;
    int waiting_time;
    void (*method)(char *, client_t *, server_t *);
} ai_handler_t;

typedef struct {
    char *name;
    int nb_arg;
    void (*method)(int, char **, server_t *);
    char *usage;
} server_handler_t;

extern const gui_handler_t gui_cmd_handler[];
extern const ai_handler_t ai_cmd_handler[];
extern const server_handler_t server_cmd_handler[];
extern const elevation_requirement_t elevation_req[];

extern const double resource_density[NB_ITEM];
extern const char *object_list[NB_ITEM];
extern const char *args[];

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
void handle_server_input(server_t *server);
void remove_elevation_req(client_t *client, server_t *server, int level);
bool check_elevation_req(client_t *client, server_t *server,
    int level, bool last_check);
bool is_part_of_elevation(client_t *client, client_t *mate);
void append_with_space_if_needed(char *buff, const char *str, bool *first);
void get_item_str(char *buff, int x, int y, server_t *server);
void append_with_coma_if_needed_x(client_t *client, char *buff, int x, int i);
void append_with_coma_if_needed_y(client_t *client, char *buff, int y, int i);
team_t *condition_win(server_t *server);

// args management
void get_port_and_freq(const char **argv, server_t *server, int i);
void get_map_size(const char **argv, game_t *game, int i);
void get_clients_nb(const char **argv, server_t *server, int i);
void get_teams_name(const char **argv, server_t *server, int i, int argc);
void check_arg_validity(server_t *server);

// gui command
void msz_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void sgt_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void sst_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void tna_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void plv_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void ppo_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void mct_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void bct_cmd(int nb_args, char **argv, client_t *client, server_t *server);
void pin_cmd(int nb_args, char **argv, client_t *client, server_t *server);

// gui reply
void pdi_reply(server_t *server, client_t *client);
void pdr_reply(server_t *server, client_t *client, int nb_resource);
void pgt_reply(server_t *server, client_t *client, int nb_resource);
void smg_reply(server_t *server, char *message);
void ppo_reply(server_t *server, client_t *client);
void pin_reply(server_t *server, client_t *client);
void pnw_reply(server_t *server, client_t *client);
void enw_reply(server_t *server, client_t *client, egg_t *new_egg);
void pfk_reply(server_t *server, client_t *client);
void ebo_reply(server_t *server, egg_t *new_egg);
void bct_reply(server_t *server, int x, int y);
void pic_reply(server_t *server, client_t *client);
void pie_reply(server_t *server, client_t *client, bool success);
void plv_reply(server_t *server, client_t *client);
void pbc_reply(server_t *server, client_t *client, char *message);
void pex_reply(server_t *server, client_t *client);
void edi_reply(server_t *server, client_t *client, egg_t *new_egg);
void seg_reply(server_t *server, team_t *winner_team);

// ai command
void inventory_cmd(char *argv, client_t *client, server_t *server);
void forward_cmd(char *argv, client_t *client, server_t *server);
void right_cmd(char *argv, client_t *client, server_t *server);
void left_cmd(char *argv, client_t *client, server_t *server);
void connect_nbr_cmd(char *argv, client_t *client, server_t *server);
void take_object_cmd(char *argv, client_t *client, server_t *server);
void set_object_cmd(char *argv, client_t *client, server_t *server);
void look_cmd(char *argv, client_t *client, server_t *server);
void fork_cmd(char *argv, client_t *client, server_t *server);
void incatation_cmd(char *, client_t *client, server_t *server);
void broadcast_cmd(char *argv, client_t *client, server_t *server);
void eject_cmd(char *argv, client_t *client, server_t *server);

// server command
void tp_cmd(int argc, char **argv, server_t *server);
void level_cmd(int argc, char **argv, server_t *server);
void give_cmd(int argc, char **argv, server_t *server);
void pause_cmd(int argc, char **argv, server_t *server);
void resume_cmd(int argc, char **argv, server_t *server);
void immortal_cmd(int, char **argv, server_t *server);
void tpegg_cmd(int, char **argv, server_t *server);
void killegg_cmd(int, char **argv, server_t *server);

// game
void init_player(client_t *client, server_t *server);
void update_simulation(server_t *server);
void create_world(server_t *server);
void spawn_resource(server_t *server, game_t *game);
void update_resource(server_t *server);
void consume_food(server_t *server);

#endif /* !ZAPPY_SERVER_H_ */
