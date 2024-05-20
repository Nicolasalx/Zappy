/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_gui.hpp"

int main(int argc, char const *argv[])
{
    client_t client = {0};

    check_arg_validity(argc, argv, &client);
    create_client(&client);
    lauch_client(&client);
    delete_client(&client);
    return 0;
}
