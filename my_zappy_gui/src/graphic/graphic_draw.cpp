/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_draw
*/

#include "zappy_gui.hpp"

void Graphic::draw_sky_box()
{
    ClearBackground(RAYWHITE);
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
        DrawModel(sky_box, (Vector3){0, 0, 0}, 1.0f, WHITE);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}

void Graphic::draw_map()
{
    for (int i = 0; i < this->gameState->map_size.x; i++) {
        for (int j = 0; j < this->gameState->map_size.y; j++) {
            DrawModel(this->model_list[ISLAND], (Vector3){i * SCALE, -1.5f, j * SCALE}, 1.0f, GREEN);
        }
    }
}

void Graphic::draw_object()
{
    for (int i = 0; i < 7; i++) {
        for (auto &food : this->gameState->object_pos[i]) {
            DrawModel(this->model_list[i], (Vector3){food.x * SCALE + object_padding[i][0], 0.5f, food.y * SCALE + object_padding[i][0]}, 1.0f, RED);
        }
    }
}

void Graphic::draw_player()
{
    for (auto &player : this->gameState->players_list) {
        //DrawModel(this->model_list[PLAYER], (Vector3){player.pos.x * SCALE, 0.5f, player.pos.y * SCALE}, 1.0f, BLUE);
        std::cout << player.orientation << std::endl;
        if (player.orientation == 1)
            DrawModelEx(this->model_list[PLAYER], (Vector3){player.pos.x * SCALE, 0.5f, player.pos.y * SCALE}, (Vector3){0, 1, 0}, 180, (Vector3){1, 1, 1}, WHITE);
        else if (player.orientation == 2)
            DrawModelEx(this->model_list[PLAYER], (Vector3){player.pos.x * SCALE, 0.5f, player.pos.y * SCALE}, (Vector3){0, 1, 0}, 90, (Vector3){1, 1, 1}, WHITE);
        else if (player.orientation == 3)
            DrawModelEx(this->model_list[PLAYER], (Vector3){player.pos.x * SCALE, 0.5f, player.pos.y * SCALE}, (Vector3){0, 1, 0}, 0, (Vector3){1, 1, 1}, WHITE);
        else if (player.orientation == 4)
            DrawModelEx(this->model_list[PLAYER], (Vector3){player.pos.x * SCALE, 0.5f, player.pos.y * SCALE}, (Vector3){0, 1, 0}, 270, (Vector3){1, 1, 1}, WHITE);
    }
}