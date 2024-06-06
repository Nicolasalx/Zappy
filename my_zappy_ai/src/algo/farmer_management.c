/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"

void look_for_elem(client_t *client)
{
    push_new_command(client, LOOK, "Look\n");
}

void take_elements_on_floor(client_t *client)
{
    char buffer[100] = {0};

    if (client->player.content_look[0][TILE_PLAYER] > 5) {
        push_new_command(client, INVENTORY, "Inventory\n");
        return;
    }
    for (int i = 0; i < (TILE_NB_ELEM - 1); ++i) {
        if (client->player.content_look[0][i] > 0) {
            snprintf(buffer, sizeof(buffer), "Take %s\n", tile_list[i]);
            push_new_command(client, TAKE, buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
    push_new_command(client, INVENTORY, "Inventory\n");
}

static void add_next_move(client_t *client, cmd_list_t action)
{
    cmd_list_t *new_action = NULL;

    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    new_action = my_calloc(sizeof(cmd_list_t));
    *new_action = action;
    append_node(&client->player.cmd_list, create_node(new_action));
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
}

static void go_backward(client_t *client)
{
    push_new_command(client, LEFT, "Left\n");
    add_next_move(client, LEFT);
    push_new_command(client, LEFT, "Left\n");
    add_next_move(client, LEFT);
    push_new_command(client, FORWARD, "Forward\n");
    add_next_move(client, FORWARD);
}

static void go_left(client_t *client)
{
    push_new_command(client, LEFT, "Left\n");
    add_next_move(client, LEFT);
    push_new_command(client, FORWARD, "Forward\n");
    add_next_move(client, FORWARD);
}

static void go_right(client_t *client)
{
    push_new_command(client, RIGHT, "Right\n");
    add_next_move(client, RIGHT);
    push_new_command(client, FORWARD, "Forward\n");
    add_next_move(client, FORWARD);
}

void move_next_case(client_t *client)
{
    int random_direction = rand() % 4;

    switch (random_direction) {
    case 0:
        push_new_command(client, FORWARD, "Forward\n");
        add_next_move(client, FORWARD);
        break;
    case 1:
        go_left(client);
        break;
    case 2:
        go_backward(client);
        break;
    case 3:
        go_right(client);
        break;
    }
    if (my_listlen(client->player.cmd_list) < 63) {
        client->instruction_index -= 3;
    }
}

void start_backtrace(client_t *client)
{
    push_new_command(client, LEFT, "Left\n");
    push_new_command(client, LEFT, "Left\n");
}

void farmer_backtrace(client_t *client)
{
    switch (*GET_DATA(client->player.cmd_list->prev, cmd_list_t)) {
        case FORWARD:
            push_new_command(client, FORWARD, "Forward\n");
            break;
        case RIGHT:
            push_new_command(client, LEFT, "Left\n");
            break;
        case LEFT:
            push_new_command(client, RIGHT, "Right\n");
            break;
        default:
            break;
    }
    pthread_mutex_lock(&get_thread_list(NULL)->mutex);
    delete_node(&client->player.cmd_list, client->player.cmd_list->prev);
    pthread_mutex_unlock(&get_thread_list(NULL)->mutex);
    if (client->player.cmd_list) {
        client->instruction_index -= 1;
    }
}
