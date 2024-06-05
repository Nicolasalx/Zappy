/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_client_input
*/

#include "zappy_server.h"

static void safe_strncat(char *dest,
    size_t *size_dest, const char *src, size_t n)
{
    size_t size_src = strlen(src);

    if ((*size_dest + size_src) >= BUFFER_SIZE - 1) {
        dprintf(2, MAGENTA("[WARNING] internal buffer full.")"\n");
        memset(dest, 0, BUFFER_SIZE);
        *size_dest = 0;
        return;
    }
    strncat(dest, src, n);
    *size_dest += size_src;
}

static void buffering_input(server_t *server,
    client_t *client, char *command, size_t nb_byte)
{
    char *start_cmd = command;
    char *end_cmd = strchr(command, '\n');

    while (end_cmd != NULL) {
        safe_strncat(client->cmd_buffer, &client->buffer_size,
            command, (end_cmd + 1) - start_cmd);
        handle_client_input(server, client, client->cmd_buffer);
        if (!client->cmd_buffer) {
            return;
        }
        memset(client->cmd_buffer, 0, BUFFER_SIZE);
        client->buffer_size = 0;
        memmove(start_cmd, end_cmd + 1, strlen(end_cmd + 1) + 1);
        end_cmd = strchr(command, '\n');
    }
    safe_strncat(client->cmd_buffer, &client->buffer_size, start_cmd, nb_byte);
}

void get_client_input(server_t *server, client_t *client)
{
    char cmd_data[BUFFER_SIZE + 1] = {0};
    ssize_t nb_byte = read(client->fd, &cmd_data, BUFFER_SIZE);

    if (nb_byte < 0) {
        return;
    }
    if (nb_byte == 0) {
        printf(YELLOW("A client has left")"\n");
        pdi_reply(server, client);
        remove_client(client);
        return;
    }
    if (nb_byte > BUFFER_SIZE) {
        dprintf(2, MAGENTA("[WARNING] too long command.")"\n");
        memset(client->cmd_buffer, 0, BUFFER_SIZE);
        client->buffer_size = 0;
        return;
    }
    buffering_input(server, client, cmd_data, nb_byte);
}
