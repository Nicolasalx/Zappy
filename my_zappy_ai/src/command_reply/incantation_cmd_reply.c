/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation
*/

#include "zappy_ai.h"

void incantation_command_reply(client_t *client, char *reply)
{
    int nb_word = 0;
    int *size_word = NULL;
    char **word = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    nb_word = count_nb_word(reply, ":");
    size_word = count_size_word(reply, ":", nb_word);
    word = my_str_to_word(reply, ":", nb_word, size_word);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
    if (strcmp(reply, "ko\n") == 0
    || strcmp(reply, "Elevation underway\n") == 0) {
        return;
    }
    if (nb_word != 2) {
        return;
    }
    if (strcmp(word[0], "Current level") == 0) {
        client->level_player = atoi(word[1]);
    }
}
