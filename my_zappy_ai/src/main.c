/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_ai.h"

int main(int argc, char const *argv[])
{
    client_t client = {0};

    srand(time(NULL));
    get_args(argc, argv, &client);
    create_client(&client);
    launch_client(&client);
    delete_client(&client);
    wait_for_child();
    free_all_alloc();
    return 0;
}
