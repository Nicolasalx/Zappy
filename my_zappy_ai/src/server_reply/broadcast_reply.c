/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** broadcast_reply
*/

#include "zappy_ai.h"

// void broad_cast_cmd(client_t *client)
// {
//     send_command_broad_cast(client, "Queen role taken");
// }

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

    printf("SAME TEAM\n");

    //int nb_word = count_nb_word(reply, " \t\n");
    //int *size_word = count_size_word(reply, " \t\n", nb_word);
    //char **word = my_str_to_word(reply, " \t\n", nb_word, size_word);

    //for (int i = 0; i < NB_ITEM; ++i) {
    //    client->shared_inventory[i] += atoi(word[i + 2]); // pcq word[0] c'est "message" et word[1] c'est <orientation>,
    //}
}
