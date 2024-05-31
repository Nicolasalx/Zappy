/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_new_ai
*/

#include "zappy_ai.h"
#include <sys/wait.h>

void remove_thread_from_list(void)
{
    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    node_t *head = get_thread_list(NULL)->thread_list;
    node_t *current = get_thread_list(NULL)->thread_list;
    pthread_t current_thread = pthread_self();

    if (head == NULL) {
        return;
    }
    do {
        if (*GET_DATA(current, pthread_t) == current_thread) {
            delete_node(&get_thread_list(NULL)->thread_list, current);
            break;
        }
        current = current->next;
    } while (current != head);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
}

static void *create_new_ai_helper(void *arg)
{
    ai_arg_t *ai_arg = (ai_arg_t *) arg;
    client_t client = {0};

    client.port = ai_arg->port;
    client.server_address.sin_addr = ai_arg->address;
    strcpy(client.player.team_name, ai_arg->team_name);
    create_client(&client);
    launch_client(&client);
    delete_client(&client);
    remove_thread_from_list();
    return NULL;
}

void create_new_ai(int port, struct in_addr address, char *team_name)
{
    pthread_t *new_thread = NULL;
    ai_arg_t *arg = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    if (my_listlen(get_thread_list(NULL)->thread_list) > 30) {
        pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
        return;
    }
    new_thread = my_calloc(sizeof(pthread_t));
    arg = my_calloc(sizeof(ai_arg_t));
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);

    arg->port = port;
    arg->address = address;
    strcpy(arg->team_name, team_name);
    pthread_create(new_thread, NULL, create_new_ai_helper, arg);
    pthread_detach(*new_thread);

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    append_node(&get_thread_list(NULL)->thread_list, create_node(new_thread));
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
}

void wait_for_child(void)
{
    while (true)
    {
        pthread_mutex_lock(&get_thread_list(NULL)->mutex);
        printf("my list len: %d\n", my_listlen(get_thread_list(NULL)->thread_list));
        if (my_listlen(get_thread_list(NULL)->thread_list) <= 0) {
            pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
            return;
        }
        pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
        sleep(1);
    }
}

void cancel_child(void)
{
    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    node_t *head = get_thread_list(NULL)->thread_list;
    node_t *current = get_thread_list(NULL)->thread_list;

    if (head == NULL) {
        return;
    }
    do {
        pthread_cancel(*GET_DATA(current, pthread_t));
        current = current->next;
    } while (current != head);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
}
