/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** incantation
*/

#include "zappy_ai.h"

void incantation_command_reply(client_t *client, char *reply)
{
    int nb_word = count_nb_word(reply, " ");
    int *size_word = count_size_word(reply, " ", nb_word);
    char **word = my_str_to_word(reply, " ", nb_word, size_word);

    if (strcmp(reply, "ko\n") == 0 || strcmp(reply, "Elevation underway\n") == 0) {
        return;
    }
    if (nb_word != 2) {
        return;
    }
    if (strcmp(word[0], "Current level") == 0) {
        client->level_player = atoi(word[1]);
    }
    printf("Incantation\n");
    printf("NEW LEVEL: %d\n", client->level_player);
}
