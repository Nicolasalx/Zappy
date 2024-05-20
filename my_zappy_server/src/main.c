/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_server.h"

int main(int argc, char const *argv[])
{
    server_t server = {0};

    check_arg_validity(argc, argv, &server);
    create_server(&server);
    lauch_server(&server);
    delete_server(&server);
    free_all_alloc();
    return 0;
}
