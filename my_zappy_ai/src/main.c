/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

#include "zappy_ai.h"
#include <signal.h>

ai_thread_t *get_thread_list(ai_thread_t *thread_list)
{
    static ai_thread_t *thread_list_save = NULL;

    if (thread_list) {
        thread_list_save = thread_list;
    }
    return thread_list_save;
}

void close_ai(int)
{
    cancel_child();
    sem_destroy(&get_thread_list(NULL)->end_game);
    pthread_mutex_destroy(&get_thread_list(NULL)->mutex);
    my_exit(0);
}

int main(int argc, char const *argv[])
{
    ai_thread_t ai_thread = {0};
    client_t client = {0};

    get_thread_list(&ai_thread);
    get_args(argc, argv);

    pthread_mutex_init(&ai_thread.mutex, NULL);
    sem_init(&ai_thread.end_game, 0, 0);

    signal(SIGINT, close_ai);
    create_new_ai(client.port,
        client.server_address.sin_addr, client.player.team_name);

    sem_wait(&ai_thread.end_game);

    cancel_child();
    sem_destroy(&ai_thread.end_game);
    pthread_mutex_destroy(&ai_thread.mutex);
    free_all_alloc();
    return 0;
}
