/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** inventory_command_reply
*/

#include "zappy_ai.h"
#include <string.h>

void remove_first_and_last_char(char **str)
{
    if (*str == NULL) {
        return;
    }
    int len = strlen(*str);

    if (len < 4) {
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        (*str)[i] = (*str)[i + 1];
    }
    (*str)[len - 3] = '\0';
}

void analyse_each_element_inventory(client_t *client, char *element)
{
    int nb_word = count_nb_word(element, " ");
    int *size_word = count_size_word(element, " ", nb_word);
    char **word = my_str_to_word(element, " ", nb_word, size_word);

    if (nb_word != 2) {
        return;
    }
    for (int i = 0; i < NB_ITEM; i++) {
        if (strcmp(word[0], object_list[i]) == 0) {
            client->player.inventory[i] = atoi(word[1]);
        }
    }
}

void parse_inventory_command(client_t *client, char *reply)
{
    remove_first_and_last_char(&reply);

    int nb_word = count_nb_word(reply, ",");
    int *size_word = count_size_word(reply, ",", nb_word);
    char **word = my_str_to_word(reply, ",", nb_word, size_word);

    for (int i = 0; word[i] != NULL; ++i) {
        analyse_each_element_inventory(client, word[i]);
    }
    //for (int i = 0; i < NB_ITEM; ++i) {
    //    printf("ITEM: %s | NB: %d\n", object_list[i], client->inventory[i]);
    //}
}

void inventory_command_reply(client_t *client, char *reply)
{
    if (reply == NULL || (strlen(reply) && reply[0] != '[')) {
        return;
    }
    parse_inventory_command(client, reply);

    client->last_cmd = LOOK;
    send_cmd_to_server(client, "Look\n");
}
