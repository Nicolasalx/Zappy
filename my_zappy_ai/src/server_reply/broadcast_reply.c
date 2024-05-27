/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_reply
*/

#include "zappy_ai.h"

void broadcast_reply(client_t *client, char *reply)
{
    int nb_word = count_nb_word(reply, " \t\n");
    int *size_word = count_size_word(reply, " \t\n", nb_word);
    char **word = my_str_to_word(reply, " \t\n", nb_word, size_word);

    for (int i = 0; i < NB_ITEM; ++i) {
        client->shared_inventory[i] += atoi(word[i + 2]);
    }
}