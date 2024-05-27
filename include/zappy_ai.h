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
    DEAD_FORK
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
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct {
    int fd;
    fd_set read_set;
    fd_set write_set;
    int port;
    struct sockaddr_in server_address;
    log_state_t log_state;
    int id;
    int world_size_x;
    int world_size_y;
    char team_name[MAX_TEAMNAME_SIZE + 1];
    char *reply_buffer;
    size_t buffer_size;
    cmd_list_t last_cmd;
    strategy_t *strategy;
    int inventory[NB_ITEM];
} client_t;

typedef struct {
    cmd_list_t cmd_type;
    void (*method)(client_t *, char *);
} reply_handler_t;

extern const reply_handler_t reply_handler[];

extern node_t *child_list;

typedef struct {
    void (**current_instruction)(client_t *);
    void (**method)(client_t *);
} cmd_to_make_t;

extern cmd_to_make_t strategy_handler_t[];

//{
//    incantation_command,
//    try_take_food,
//    forward_command
//}

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

// reply handler
void first_action(client_t *client, char *reply);
void forward_command(client_t *client, char *reply);
void right_command(client_t *client, char *reply);
void left_command(client_t *client, char *reply);
void look_command(client_t *client, char *reply);
void inventory_command(client_t *client, char *reply);
void broadcast_command(client_t *client, char *reply);
void connect_nbr_command(client_t *client, char *reply);
void fork_command(client_t *client, char *reply);
void eject_command(client_t *client, char *reply);
void take_command(client_t *client, char *reply);
void set_command(client_t *client, char *reply);
void incantation_command(client_t *client, char *reply);

#endif /* !ZAPPY_AI_H_ */
