/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look
*/

#include "zappy_ai.h"

void analyse_each_element_look(client_t *client, char *element, int tile_nb)
{
    int nb_word = count_nb_word(element, " ");
    int *size_word = count_size_word(element, " ", nb_word);
    char **word = my_str_to_word(element, " ", nb_word, size_word);

    if (nb_word == 0) {
        return;
    }
    for (int i = 0; word[i] != NULL; ++i) {
        for (int j = 0; j < TILE_NB_ELEM; j++) {
            if (strcmp(word[i], tile_list[j]) == 0) {
                client->player.content_look[tile_nb][j] += 1;
            }
        }
    }
}

void parse_look_command(client_t *client, char *reply)
{
    int tile_nb = 0;

    remove_first_and_last_char(&reply);

    int nb_word = count_nb_word_opt(reply, ",");
    int *size_word = count_size_word_opt(reply, ",", nb_word);
    char **word = my_str_to_word_opt(reply, ",", nb_word, size_word);

    memset(client->player.content_look, 0, sizeof(int) * MAX_LOOK_SIZE * TILE_NB_ELEM);
    for (int i = 0; word[i] != NULL; ++i) {
        analyse_each_element_look(client, word[i], tile_nb);
        ++tile_nb;
    }

    // printf("\n\n\n\n");
    // printf("NB TILE: %d\n", tile_nb);
    // for (int i = 0; i < tile_nb; ++i) {
    //     printf("TILE n°%d\n", i);
    //     for (int j = 0; j < TILE_NB_ELEM; ++j) {
    //         printf("ITEM: %s | NB: %d\n", tile_list[j], client->content_look[i][j]);
    //     }
    // }
}

void look_command(client_t *client, char *reply)
{
    parse_look_command(client, reply);
}
