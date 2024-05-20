/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** send_reply_to_client
*/

#include "zappy_server.h"

void send_reply_to_client(int fd, char *reply_data)
{
    if (FD_ISSET(fd, &get_server(NULL)->write_set)) {
        if (send(fd, reply_data, strlen(reply_data), 0) == -1) {
            my_putstr(RED("Fail to send reply to client.\n"));
        }
    }
}
