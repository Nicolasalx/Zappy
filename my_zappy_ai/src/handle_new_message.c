/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "zappy_ai.h"

static void safe_strncat(char *dest, size_t *size_dest, const char *src, size_t n)
{
    size_t size_src = strlen(src);

    if ((*size_dest + size_src) >= CMD_BUFFER_SIZE - 1) {
        dprintf(2, MAGENTA("[WARNING] internal buffer full.")"\n");
        memset(dest, 0, CMD_BUFFER_SIZE);
        *size_dest = 0;
        return;
    }
    strncat(dest, src, n);
    *size_dest += size_src;
}

static void buffering_input(client_t *client, char *command, size_t nb_byte)
{
    char *start_cmd = command;
    char *end_cmd = strchr(command, '\n');

    while (end_cmd != NULL) {
        safe_strncat(client->reply_buffer, &client->buffer_size, command, (end_cmd + 1) - start_cmd);
        handle_server_reply(client, client->reply_buffer);

        memset(client->reply_buffer, 0, CMD_BUFFER_SIZE);
        client->buffer_size = 0;
        memmove(start_cmd, end_cmd + 1, strlen(end_cmd + 1) + 1);
        end_cmd = strchr(command, '\n');
    }
    safe_strncat(client->reply_buffer, &client->buffer_size, start_cmd, nb_byte);
}

void handle_new_message(client_t *client)
{
    char reply[BUFFER_SIZE + 1] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(client->fd, &client->read_set)) {
        return;
    }
    size = read(client->fd, &reply, sizeof(reply) - 1);
    if (size == 0) {
        exit_client(client, 0, "Server closed the connection.\n");
    } else if (size < 0) {
        exit_client(client, 84, RED("Fail to read message.\n"));
    }
    if (size > BUFFER_SIZE) {
        dprintf(2, MAGENTA("[WARNING] too long command.")"\n");
        memset(client->reply_buffer, 0, BUFFER_SIZE);
        client->buffer_size = 0;
        return;
    }
    buffering_input(client, reply, size);
}
