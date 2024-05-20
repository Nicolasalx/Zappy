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

typedef struct {
    int fd;
} client_t;

typedef struct {
    unsigned short port;
    int width;
    int height;
    int client_nb;
    int freq;
    char *teams[MAX_TEAM_NB];
} args_t;

typedef struct {
    int fd;
    struct sockaddr_in address;
    fd_set read_set;
    fd_set write_set;
    client_t clients[MAX_CLIENT];
    args_t args;
} server_t;

void check_arg_validity(int argc, const char **argv, server_t *server);
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
void execute_client_input(server_t *server,
    client_t *client, char *cmd_data);

#endif /* !MYTEAMS_SERVER_H_ */
