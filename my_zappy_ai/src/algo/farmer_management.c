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

    for (int i = 0; i < TILE_NB_ELEM; ++i) {
        if (client->player.content_look[0][i] > 0) {
            char result[250] = {0};
            snprintf(result, sizeof(result), "Take %s\n", tile_list[i]);
            push_new_command(client, TAKE, result);
            printf("EAT %s\n", tile_list[i]);
            farmer_take_elem = true;
        }
    }
    if (!farmer_take_elem) {
        push_new_command(client, INVENTORY, "Inventory\n");
    }
}

void move_next_case(client_t *client)
{
    int random_direction = rand() % 4;

    switch (random_direction) {
        case 0:
            printf("FORWARD\n");
            push_new_command(client, FORWARD, "Forward\n");
            break;
        case 1:
            printf("GO LEFT\n");
            push_new_command(client, LEFT, "Left\n");
            push_new_command(client, FORWARD, "Forward\n");
            break;
        case 2:
            printf("GO BACK\n");
            push_new_command(client, LEFT, "Left\n");
            push_new_command(client, LEFT, "Left\n");
            push_new_command(client, FORWARD, "Forward\n");
            break;
        case 3:
            printf("GO RIGHT\n");
            push_new_command(client, RIGHT, "Right\n");
            push_new_command(client, FORWARD, "Forward\n");
            break;
        default:
            push_new_command(client, FORWARD, "Forward\n");
            break;
    }
}
