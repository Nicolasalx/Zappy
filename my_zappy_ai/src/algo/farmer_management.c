/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** queen_management
*/

#include "zappy_ai.h"

/* TODO
    Detect if the farmer needs to go back
    Go back to the base

    15 actions per food loss
*/

void look_for_elem(client_t *client)
{
    push_new_command(client, LOOK, "Look\n");
}

void take_elements_on_floor(client_t *client)
{
    char buffer[100] = {0};

    for (int i = 0; i < TILE_NB_ELEM; ++i) {
        if (client->player.content_look[0][i] > 0) {
            snprintf(buffer, sizeof(buffer), "Take %s\n", tile_list[i]);
            push_new_command(client, TAKE, buffer);
            printf("TAKE %s\n", buffer);
            memset(buffer, 0, sizeof(buffer));
        }
    }
    push_new_command(client, INVENTORY, "Inventory\n");
}

void add_next_move(client_t *client, cmd_list_t action)
{
    cmd_list_t *new_action = my_calloc(sizeof(cmd_list_t));
    *new_action = action;
    append_node(&client->player.cmd_list, create_node(new_action));
}

void move_next_case(client_t *client)
{
    int random_direction = rand() % 4;

    switch (random_direction) {
        case 0:
            printf("FORWARD\n");
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
        case 1:
            printf("GO LEFT\n");
            push_new_command(client, LEFT, "Left\n");
            add_next_move(client, RIGHT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
        case 2:
            printf("GO BACK\n");
            push_new_command(client, LEFT, "Left\n");
            add_next_move(client, RIGHT);
            push_new_command(client, LEFT, "Left\n");
            add_next_move(client, RIGHT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
        case 3:
            printf("GO RIGHT\n");
            push_new_command(client, RIGHT, "Right\n");
            add_next_move(client, LEFT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
    }
    if (client->player.inventory[FOOD] > 5) {
        client->instruction_index -= 2;
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
    delete_node(&client->player.cmd_list, client->player.cmd_list->prev);
    if (client->player.cmd_list) {
        client->instruction_index -= 1;
    }
}

void farmer_drop_items(client_t *client)
{
    char buffer[100] = {0};

    for (int i = NB_ITEM; i > 0; --i) {
        if (client->player.inventory[i] > 0) {
            snprintf(buffer, sizeof(buffer), "Set %s\n", object_list[i]);
            push_new_command(client, SET, buffer);
            memset(buffer, 0, sizeof(buffer));
            break;
        } 
    }
    client->instruction_index -= 1;
}