/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_reply
*/

#include "zappy_ai.h"

void broadcast_reply(client_t *client, char *reply)
{
    char **word = my_str_to_word_array(reply, " ");

    for (int i = 0; i < NB_ITEM; ++i) {
        client->shared_inventory[i] += atoi(word[i + 2]); // pcq word[0] c'est "message" et word[1] c'est <orientation>,
    }
}