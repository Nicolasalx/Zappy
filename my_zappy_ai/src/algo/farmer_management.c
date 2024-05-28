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
    bool farmer_take_elem = false;
    char buffer[100] = {0};


    for (int i = 0; i < TILE_NB_ELEM; ++i) {
        if (client->player.content_look[0][i] > 0) {
            snprintf(buffer, sizeof(buffer), "Take %s\n", tile_list[i]);
            push_new_command(client, TAKE, buffer);
            printf("TAKE %s\n", tile_list[i]);
            farmer_take_elem = true;
            memset(buffer, 0, sizeof(buffer));
        }
    }
    if (!farmer_take_elem) {
        push_new_command(client, INVENTORY, "Inventory\n");
    }
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
            add_next_move(client, LEFT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
        case 2:
            printf("GO BACK\n");
            push_new_command(client, LEFT, "Left\n");
            add_next_move(client, LEFT);
            push_new_command(client, LEFT, "Left\n");
            add_next_move(client, LEFT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
        case 3:
            printf("GO RIGHT\n");
            push_new_command(client, RIGHT, "Right\n");
            add_next_move(client, RIGHT);
            push_new_command(client, FORWARD, "Forward\n");
            add_next_move(client, FORWARD);
            break;
    }
}

void farmer_management(client_t *client)
{
    if (client->player.inventory[FOOD] < 50) {
        push_new_command(client, TAKE, "Take food\n");
        push_new_command(client, INVENTORY, "Inventory\n");
    } else {
        if (client->player.inventory[FOOD] < 10) {
            push_new_command(client, SET, "Look\n");
        }
    }
}
