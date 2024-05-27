/*
** EPITECH PROJECT, 2024
** B-YED-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy_ai
*/

#ifndef ZAPPY_AI_H_
    #define ZAPPY_AI_H_

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

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 100000
    #define NEW_CLIENT_MESSAGE "WELCOME\n"
    #define MAX_TEAMNAME_SIZE 32
    #define MAX_LOOK_SIZE 81

typedef enum {
    WAITING_WELCOME,
    WAITING_ID,
    WAINTING_MAP_SIZE,
    LOGGED
} log_state_t;

typedef enum {
    NOT_SET,
    FARMER,
    QUEEN,
    DEAD_FORK,
    NB_STRATEGY
} strategy_t;

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
    TILE_FOOD,
    TILE_LINEMATE,
    TILE_DERAUMERE,
    TILE_SIBUR,
    TILE_MENDIANE,
    TILE_PHIRAS,
    TILE_THYSTAME,
    TILE_PLAYER,
    TILE_NB_ELEM
} tile_t;
    
typedef enum {
    NONE,
    FORWARD,
    RIGHT,
    LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT_NBR,
    FORK,
    EJECT,
    TAKE,
    SET,
    INCANTATION,
    NB_ACTION
} cmd_list_t;

typedef struct {
    int id;
    int inventory[NB_ITEM];
    int content_look[MAX_LOOK_SIZE][TILE_NB_ELEM];
    char team_name[MAX_TEAMNAME_SIZE + 1];
    item_t last_item_taken;
} player_t;

typedef struct {
    int size_x;
    int size_y;
} world_t;

typedef struct {
    int fd;
    int port;
    struct sockaddr_in server_address;
    fd_set read_set;
    fd_set write_set;
    world_t world;
    player_t player;
    log_state_t log_state;
    char *reply_buffer;
    size_t buffer_size;
    strategy_t strategy;
    int shared_inventory[NB_ITEM];
    int instruction_index;
    int remaining_spots;
    node_t *cmd_to_make;
    cmd_list_t last_cmd;
    int level_player;
} client_t;

typedef struct {
    cmd_list_t cmd_type;
    char *arg;
} cmd_to_make_t;

typedef struct {
    cmd_list_t cmd_type;
    void (*method)(client_t *, char *);
} reply_handler_t;

extern const reply_handler_t reply_handler[];

extern node_t *child_list;


//{
//    incantation_command,
//    try_take_food,
//    forward_command
//}
extern void (*strategy_handler[NB_STRATEGY][10])(client_t *);
extern const char *object_list[NB_ITEM];
extern const char *tile_list[TILE_NB_ELEM];

void check_arg_validity(int argc, const char **argv, client_t *client);
void get_args(int argc, const char **argv, client_t *client);
void create_client(client_t *client);
client_t *get_client(client_t *client);
void init_client_set(client_t *client, int *max_fd);
void monitor_input(client_t *client, int max_fd);

void handle_new_message(client_t *client);
void handle_server_reply(client_t *client, char *reply);
void send_cmd_to_server(client_t *client, char *cmd);
void handle_cmd_reply(client_t *client, char *reply);

void launch_client(client_t *client);
void delete_client(client_t *client);
void exit_client(int exit_value, const char *message);

void create_new_ai(int port, struct in_addr *address, char *team_name);
void wait_for_child(void);

void push_new_command(client_t *client, cmd_list_t cmd_type, char *cmd);
void pop_cmd_to_make(client_t *client);

// reply handler
void first_action_reply(client_t *client, char *reply);
void forward_command_reply(client_t *client, char *reply);
void right_command_reply(client_t *client, char *reply);
void left_command_reply(client_t *client, char *reply);
void look_command_reply(client_t *client, char *reply);
void inventory_command_reply(client_t *client, char *reply);
void broadcast_command_reply(client_t *client, char *reply);
void connect_nbr_command_reply(client_t *client, char *reply);
void fork_command_reply(client_t *client, char *reply);
void eject_command_reply(client_t *client, char *reply);
void take_command_reply(client_t *client, char *reply);
void set_command_reply(client_t *client, char *reply);
void incantation_command_reply(client_t *client, char *reply);

void remove_first_and_last_char(char **str);

void queen_management(client_t *client);

#endif /* !ZAPPY_AI_H_ */
