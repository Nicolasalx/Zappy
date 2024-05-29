/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

void Graphic::change_cursor()
{
    if (IsKeyPressed(KEY_P) && !this->cursor) {
        EnableCursor();
        this->cursor = true;
    } else if (IsKeyPressed(KEY_P) && this->cursor) {
        DisableCursor();
        this->cursor = false;
    }
}

void Graphic::window_resize()
{
    if (IsWindowResized()) {
        this->window_width = GetScreenWidth();
        this->window_height = GetScreenHeight();
        for (auto &textBox : this->textBoxs) {
            textBox.resize(this->window_width, this->window_height);
        }
    }
}

void Graphic::click_event()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        this->rayInfo.ray = GetMouseRay(GetMousePosition(), this->camera);
        for (auto &player : this->gameState->players_list) {
            this->rayInfo.box.min = (Vector3){player.real_pos.x * SCALE -1.0f, 0.0f, player.real_pos.y * SCALE - 1.0f};
            this->rayInfo.box.max = (Vector3){player.real_pos.x * SCALE + 1.0f, 3.0f, player.real_pos.y * SCALE + 1.0f};
            this->rayInfo.collision.hit = false;
            this->rayInfo.collision = GetRayCollisionBox(this->rayInfo.ray, this->rayInfo.box);
            if (this->rayInfo.collision.hit && this->rayInfo.collision.distance <  __FLT_MAX__) {
                this->rayInfo.type = PLAYER;
                this->rayInfo.id = player.n;
                return;
            }
        }
        for (int y = 0; y < this->gameState->map_size.y; y++) {
            for (int x = 0; x < this->gameState->map_size.y; x++) {
                this->rayInfo.box.min = (Vector3){x * SCALE - 2.0f, -4.0f, y * SCALE - 2.0f};
                this->rayInfo.box.max = (Vector3){x * SCALE + 2.0f, 0.0f, y * SCALE + 2.0f};
                this->rayInfo.collision.hit = false;
                this->rayInfo.collision = GetRayCollisionBox(this->rayInfo.ray, this->rayInfo.box);
                if (this->rayInfo.collision.hit && this->rayInfo.collision.distance <  __FLT_MAX__) {
                    this->rayInfo.type = ISLAND;
                    this->rayInfo.x = x;
                    this->rayInfo.y = y;
                    return;
                }
            }
        }
        this->rayInfo.type = 0;
        this->rayInfo.id = 0;
        this->rayInfo.x = 0;
        this->rayInfo.y = 0;
    }
}

void Graphic::change_player_selected()
{
    if (IsKeyPressed(KEY_O)) {
        for (size_t i = 0; i < this->gameState->players_list.size(); i++) {
            if (gameState->players_list[i].n == this->rayInfo.id) {
                if (i == this->gameState->players_list.size() - 1) {
                    this->rayInfo.id = this->gameState->players_list[0].n;
                } else {
                    this->rayInfo.id = this->gameState->players_list[i + 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < this->gameState->players_list.size(); i++) {
            rayInfo.id = this->gameState->players_list[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
    if (IsKeyPressed(KEY_I)) {
        for (size_t i = 0; i < this->gameState->players_list.size(); i++) {
            if (gameState->players_list[i].n == this->rayInfo.id) {
                if (i == 0) {
                    this->rayInfo.id = this->gameState->players_list[this->gameState->players_list.size() - 1].n;
                } else {
                    this->rayInfo.id = this->gameState->players_list[i - 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < this->gameState->players_list.size(); i++) {
            rayInfo.id = this->gameState->players_list[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
}

void Graphic::event()
{
    frame_time = GetFrameTime();
    if (IsCursorHidden()) UpdateCamera(&this->camera, CAMERA_FREE);
    // float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
    // SetShaderValue(light_shader, light_shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
    this->change_cursor();
    this->window_resize();
    this->click_event();
    this->change_player_selected();
}
