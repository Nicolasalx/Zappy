/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ai_thread_managment
*/

#include "zappy_ai.h"
#include <signal.h>

void init_ai_thread(ai_thread_t *ai_thread, ai_arg_t *ai_arg)
{
    get_thread_list(ai_thread);
    pthread_mutex_init(&ai_thread->mutex, NULL);
    sem_init(&ai_thread->end_game, 0, 0);
    create_new_ai(ai_arg->port,
        &ai_arg->address, ai_arg->team_name);
}

void destroy_ai_thread(ai_thread_t *ai_thread)
{
    cancel_child();
    sem_destroy(&ai_thread->end_game);
    pthread_mutex_destroy(&ai_thread->mutex);
    free_all_alloc();
}
