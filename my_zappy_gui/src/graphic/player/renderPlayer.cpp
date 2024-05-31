/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_draw_player
*/

#include "zappy_gui.hpp"
#include "player.hpp"
#include "infoGame.hpp"

static void draw_player_box(Gui::Graphic *graphic, Gui::player_t &player)
{
    if (graphic->rayInfo.type == Gui::PLAYER && graphic->rayInfo.id == player.n) {
        graphic->rayInfo.box.min = (Vector3){player.real_pos.x * SCALE -1.0f, 0.0f, player.real_pos.y * SCALE - 1.0f};
        graphic->rayInfo.box.max = (Vector3){player.real_pos.x * SCALE + 1.0f, 3.0f, player.real_pos.y * SCALE + 1.0f};
        DrawBoundingBox(graphic->rayInfo.box, GREEN);
        DrawModelEx(graphic->_modelList[Gui::PLAYER], (Vector3){player.real_pos.x * SCALE, 0.0f, player.real_pos.y * SCALE}, (Vector3){0, 1, 0}, player.real_orientation, (Vector3){3, 3, 3}, GREEN);
    }
}

static void draw_player_model(Gui::Graphic *graphic, Gui::player_t &player)
{
    DrawModelEx(graphic->_modelList[Gui::PLAYER], (Vector3){player.real_pos.x * SCALE, 0.0f, player.real_pos.y * SCALE}, (Vector3){0, 1, 0}, player.real_orientation, (Vector3){3, 3, 3}, WHITE);
}

void Gui::Graphic::draw_player()
{
    for (auto &player : this->gameState->players_list) {
        update_animation(player);
        if (rayInfo.type == PLAYER && rayInfo.id == player.n) {
            draw_player_box(this, player);
        } else {
            draw_player_model(this, player);
        }
    }
}
