/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initIsland
*/

#include "ARayLibModel.hpp"
#include "RenderRayInfo.hpp"
#include <raylib.h>

void Gui::RenderRayInfo::selectEvent(const GameData &gameData, Camera3D camera)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        this->ray = GetMouseRay(GetMousePosition(), camera);
        for (auto &player : gameData.playerList) {
            box.min = (Vector3){player.real_pos.x * Gui::MAP_SCALE -1.0, 0.0, player.real_pos.y * Gui::MAP_SCALE - 1.0};
            box.max = (Vector3){player.real_pos.x * Gui::MAP_SCALE + 1.0, 3.0, player.real_pos.y * Gui::MAP_SCALE + 1.0};
            collision.hit = false;
            collision = GetRayCollisionBox(ray, box);
            if (collision.hit && collision.distance < __FLT_MAX__) {
                rayInfo.type = PLAYER;
                rayInfo.id = player.n;
                return;
            }
        }
        for (int y = 0; y < gameData.mapSize.y; y++) {
            for (int x = 0; x < gameData.mapSize.y; x++) {
                box.min = (Vector3){x * Gui::MAP_SCALE - 2.0 * Gui::ISLAND_SIZE, -4.0 * Gui::ISLAND_SIZE, y * Gui::MAP_SCALE - 2.0 * Gui::ISLAND_SIZE};
                box.max = (Vector3){x * Gui::MAP_SCALE + 2.0 * Gui::ISLAND_SIZE, 0.0, y * Gui::MAP_SCALE + 2.0 * Gui::ISLAND_SIZE};
                collision.hit = false;
                collision = GetRayCollisionBox(ray, box);
                if (this->collision.hit && collision.distance <  __FLT_MAX__) {
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

void Gui::RenderRayInfo::changePlayerSelected(const GameData &gameData)
{
    if (IsKeyPressed(KEY_O)) {
        for (size_t i = 0; i < gameData.playerList.size(); i++) {
            if (gameData.playerList[i].n == this->rayInfo.id) {
                if (i == gameData.playerList.size() - 1) {
                    this->rayInfo.id = gameData.playerList[0].n;
                } else {
                    this->rayInfo.id = gameData.playerList[i + 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < gameData.playerList.size(); i++) {
            rayInfo.id = gameData.playerList[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
    if (IsKeyPressed(KEY_I)) {
        for (size_t i = 0; i < gameData.playerList.size(); i++) {
            if (gameData.playerList[i].n == this->rayInfo.id) {
                if (i == 0) {
                    this->rayInfo.id = gameData.playerList[gameData.playerList.size() - 1].n;
                } else {
                    this->rayInfo.id = gameData.playerList[i - 1].n;
                }
                this->rayInfo.type = PLAYER;
                return;
            }
        }
        for (size_t i = 0; i < gameData.playerList.size(); i++) {
            rayInfo.id = gameData.playerList[i].n;
            this->rayInfo.type = PLAYER;
            return;
        }
    }
}

void Gui::RenderRayInfo::render(const GameData &gameData, Camera3D camera)
{
    this->selectEvent(gameData, camera);
    this->changePlayerSelected(gameData);
}

void Gui::RenderRayInfo::addRayToEvent(Gui::Event &event)
{
    event.rayInfo = this->rayInfo;
}