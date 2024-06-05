/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_ai.h"
#include <signal.h>

int main(int argc, char const *argv[])
{
    ai_thread_t ai_thread = {0};
    ai_arg_t ai_arg = {0};

    get_args(argc, argv, &ai_arg);
    init_ai_thread(&ai_thread, &ai_arg);
    sem_wait(&ai_thread.end_game);
    destroy_ai_thread(&ai_thread);
    return 0;
}
