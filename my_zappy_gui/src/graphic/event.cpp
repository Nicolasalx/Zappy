/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "zappy_gui.hpp"

void Gui::Graphic::change_cursor()
{
    if (IsKeyPressed(KEY_P) && !this->cursor) {
        EnableCursor();
        this->cursor = true;
    } else if (IsKeyPressed(KEY_P) && this->cursor) {
        DisableCursor();
        this->cursor = false;
    }
}

void Gui::Graphic::window_resize()
{
    if (IsWindowResized()) {
        this->window.window_width = GetScreenWidth();
        this->window.window_height = GetScreenHeight();
        for (auto &textBox : this->textBoxs) {
            textBox.resize(this->window.window_width, this->window.window_height);
        }
    }
}

void Gui::Graphic::click_event()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        this->rayInfo.ray = GetMouseRay(GetMousePosition(), this->camera._data);
        for (auto &player : this->_gameState->players_list) {
            this->rayInfo.box.min = (Vector3){player.real_pos.x * Gui::MAP_SCALE -1.0f, 0.0f, player.real_pos.y * Gui::MAP_SCALE - 1.0f};
            this->rayInfo.box.max = (Vector3){player.real_pos.x * Gui::MAP_SCALE + 1.0f, 3.0f, player.real_pos.y * Gui::MAP_SCALE + 1.0f};
            this->rayInfo.collision.hit = false;
            this->rayInfo.collision = GetRayCollisionBox(this->rayInfo.ray, this->rayInfo.box);
            if (this->rayInfo.collision.hit && this->rayInfo.collision.distance <  __FLT_MAX__) {
                this->rayInfo.type = PLAYER;
                this->rayInfo.id = player.n;
                return;
            }
        }
        for (int y = 0; y < this->_gameState->map_size.y; y++) {
            for (int x = 0; x < this->_gameState->map_size.y; x++) {
                this->rayInfo.box.min = (Vector3){x * Gui::MAP_SCALE - 2.0f, -4.0f, y * Gui::MAP_SCALE - 2.0f};
                this->rayInfo.box.max = (Vector3){x * Gui::MAP_SCALE + 2.0f, 0.0f, y * Gui::MAP_SCALE + 2.0f};
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
        for (auto &textBox : this->textBoxs) {
            textBox.open_close();
        }
    }
}

void Gui::Graphic::change_player_selected()
{
    if (IsKeyPressed(KEY_O)) {
        for (size_t i = 0; i < this->_gameState->players_list.size(); i++) {
            if (_gameState->players_list[i].n == this->rayInfo.id) {
                if (i == this->_gameState->players_list.size() - 1) {
                    this->rayInfo.id = this->_gameState->players_list[0].n;
                } else {
                    this->rayInfo.id = this->_gameState->players_list[i + 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < this->_gameState->players_list.size(); i++) {
            rayInfo.id = this->_gameState->players_list[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
    if (IsKeyPressed(KEY_I)) {
        for (size_t i = 0; i < this->_gameState->players_list.size(); i++) {
            if (_gameState->players_list[i].n == this->rayInfo.id) {
                if (i == 0) {
                    this->rayInfo.id = this->_gameState->players_list[this->_gameState->players_list.size() - 1].n;
                } else {
                    this->rayInfo.id = this->_gameState->players_list[i - 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < this->_gameState->players_list.size(); i++) {
            rayInfo.id = this->_gameState->players_list[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
}

void Gui::Graphic::event()
{
    frame_time = GetFrameTime();
    if (IsCursorHidden()) UpdateCamera(&this->camera._data, CAMERA_FREE);
    // float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
    // SetShaderValue(light_shader, light_shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
    this->change_cursor();
    this->window_resize();
    this->click_event();
    this->change_player_selected();
    this->update_particle_list();
}
