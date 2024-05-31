/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_client
*/

#include "zappy_ai.h"

void create_client(client_t *client)
{
    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd == -1) {
        sem_post(&get_thread_list(NULL)->end_game);
        exit_client(client, 84, RED("Fail to create the client socket\n"));
    }
    client->server_address.sin_family = AF_INET;
    client->server_address.sin_port = htons(client->port);
    if (connect(client->fd, (struct sockaddr *)
        &client->server_address, sizeof(client->server_address)) != 0) {
        sem_post(&get_thread_list(NULL)->end_game);
        exit_client(client, 84, RED("Connection to the server failed.\n"));
    }
    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    client->reply_buffer = my_calloc(sizeof(char) * (CMD_BUFFER_SIZE + 1));
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
}
