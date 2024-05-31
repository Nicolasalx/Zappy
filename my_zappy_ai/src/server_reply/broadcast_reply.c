/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_reply
*/

#include "zappy_ai.h"

bool command_come_from_my_team(client_t *client, const char *reply)
{
    int nb_word = count_nb_word(reply, "|");
    int *size_word = count_size_word(reply, "|", nb_word);
    char **word = my_str_to_word(reply, "|", nb_word, size_word);

    if (nb_word < 3) {
        return false;
    }
    if (strcmp(client->player.team_name, word[1]) == 0) {
        return true;
    }
    return false;
}

void broadcast_reply(client_t *client, char *reply)
{
    if (!command_come_from_my_team(client, reply)) {
        return;
    }
}
