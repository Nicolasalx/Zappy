/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** get_thread_list
*/

#include "zappy_ai.h"

ai_thread_t *get_thread_list(ai_thread_t *thread_list)
{
    static ai_thread_t *thread_list_save = NULL;

    if (thread_list) {
        thread_list_save = thread_list;
    }
    return thread_list_save;
}
