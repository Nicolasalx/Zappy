/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** look_command_reply
*/

#include "zappy_ai.h"

static void get_elem_on_tile(int i, int tile_nb, char **word, client_t *client)
{
    for (int j = 0; j < TILE_NB_ELEM; j++) {
        if (strcmp(word[i], tile_list[j]) == 0) {
            client->player.content_look[tile_nb][j] += 1;
        }
    }
}

void analyse_each_element_look(client_t *client, char *element, int tile_nb)
{
    int nb_word = 0;
    int *size_word = NULL;
    char **word = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    nb_word = count_nb_word(element, " ");
    size_word = count_size_word(element, " ", nb_word);
    word = my_str_to_word(element, " ", nb_word, size_word);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
    if (nb_word == 0) {
        return;
    }
    for (int i = 0; i < nb_word; ++i) {
        get_elem_on_tile(i, tile_nb, word, client);
    }
}

void parse_look_command(client_t *client, char *reply)
{
    int tile_nb = 0;
    int nb_word = 0;
    int *size_word = NULL;
    char **word = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    nb_word = count_nb_word_opt(reply, ",");
    size_word = count_size_word_opt(reply, ",", nb_word);
    word = my_str_to_word_opt(reply, ",", nb_word, size_word);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
    remove_first_and_last_char(&reply);
    memset(client->player.content_look, 0,
        sizeof(int) * MAX_LOOK_SIZE * TILE_NB_ELEM);
    for (int i = 0; i < nb_word; ++i) {
        analyse_each_element_look(client, word[i], tile_nb);
        ++tile_nb;
    }
}

void look_command_reply(client_t *client, char *reply)
{
    parse_look_command(client, reply);
}
