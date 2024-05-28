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
        this->textBoxs[0] = (Rectangle){window_width * 0.76f, window_height / 21.0f, window_width / 4.5f, window_height / 10.0f};
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
                std::cout << "Player " << player.n << " clicked\n";
            }
        }
    }
}

void Graphic::event()
{
    if (IsCursorHidden()) UpdateCamera(&this->camera, CAMERA_FREE);
    // float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
    // SetShaderValue(light_shader, light_shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
    if (IsKeyPressed(KEY_Z)) {
        this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    }
    this->change_cursor();
    this->window_resize();
    this->click_event();
}
