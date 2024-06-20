/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** initPlayer
*/

#include "RenderCamera.hpp"
#include "RenderIsland.hpp"
#include "RenderEndGame.hpp"
#include <complex>

Gui::RenderCamera::RenderCamera()
{
    this->_camera.position = (Vector3){ 0.0, 10.0, 0.0 };
    this->_camera.target = (Vector3){ 50.0, 0.0, 50.0 };
    this->_camera.up = (Vector3){ 0.0, 1.0, 0.0 };
    this->_camera.fovy = 90.0;
    this->_camera.projection = CAMERA_PERSPECTIVE;
}

void Gui::RenderCamera::handle_cursor()
{
    if (IsKeyPressed(KEY_P) && !this->cursor) {
        EnableCursor();
        this->cursor = true;
    } else if (IsKeyPressed(KEY_P) && this->cursor) {
        DisableCursor();
        this->cursor = false;
    }
}

void Gui::RenderCamera::render(const GameData &gameData)
{
    map_dimension.x = gameData.mapSize.x;
    map_dimension.y = gameData.mapSize.y;
    if (gameData.playerList.size() == 0 || Gui::RenderEndGame::_isEndGame)
        return;
    playerPos = gameData.playerList.at(0).pos;
}

void Gui::RenderCamera::updatePlayerPos(Gui::Event &event)
{
    event.playerPos.x = this->_camera.position.x;
    event.playerPos.y = this->_camera.position.z;
}

void Gui::RenderCamera::setPlayerEndGamePos(float x, float y, float z)
{
    if (Gui::RenderEndGame::_isEndGame) {
        _x = x;
        _y = y;
        _z = z;
    }
}

void Gui::RenderCamera::playerMode()
{
    _camera.target.x = playerPos.x * Gui::RenderIsland::map_scale;
    _camera.target.z = playerPos.y * Gui::RenderIsland::map_scale;
    if (sqrt(pow(_camera.position.x - playerPos.x * Gui::RenderIsland::map_scale, 2) + pow(_camera.position.z - playerPos.y * Gui::RenderIsland::map_scale, 2)) > 7.0f) {
        if (_camera.position.x < playerPos.x * Gui::RenderIsland::map_scale)
            _camera.position.x += abs(playerPos.x * Gui::RenderIsland::map_scale - _camera.position.x) / 3.0f;
        if (_camera.position.x > playerPos.x * Gui::RenderIsland::map_scale)
            _camera.position.x -= abs(playerPos.x * Gui::RenderIsland::map_scale - _camera.position.x) / 3.0f;
        if (_camera.position.z < playerPos.y * Gui::RenderIsland::map_scale)
            _camera.position.z += abs(playerPos.y * Gui::RenderIsland::map_scale - _camera.position.z) / 3.0f;
        if (_camera.position.z > playerPos.y * Gui::RenderIsland::map_scale)
            _camera.position.z -= abs(playerPos.y * Gui::RenderIsland::map_scale - _camera.position.z) / 3.0f;
    }
    if (IsCursorHidden()) {
        UpdateCamera(&this->_camera, CAMERA_THIRD_PERSON);
    }
}

void Gui::RenderCamera::spectatorMode()
{
    if (IsCursorHidden()) {
        if (IsKeyDown(KEY_W))
            UpdateCameraPro(&this->_camera, (Vector3){GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_S))
            UpdateCameraPro(&this->_camera, (Vector3){-GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_A))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, -GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_D))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_SPACE))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_LEFT_SHIFT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, -GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_LEFT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){-GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_RIGHT))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_UP))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, -GetFrameTime() * 30, 0.0f}, 0.0f);
        if (IsKeyDown(KEY_DOWN))
            UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, GetFrameTime() * 30, 0.0f}, 0.0f);
        UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, -GetMouseWheelMove()*2.0f);
        UpdateCameraPro(&this->_camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetMouseDelta().x*0.05f, GetMouseDelta().y*0.05f, 0.0f}, 0.0f);
    }
}

void Gui::RenderCamera::spectatorTopMode()
{
    _camera.position.x = (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale - 1;
    _camera.position.y = 100.0f;
    _camera.position.z = (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale;
    _camera.target.x = (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale;
    _camera.target.y = 0.0f;
    _camera.target.z = (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale;
    _camera.fovy = Gui::RenderIsland::map_scale * 10.0f;
}

void Gui::RenderCamera::endGameMode()
{
    _camera.target.x = _x + 5 * Gui::RenderIsland::map_scale;
    _camera.target.y = _y;
    _camera.target.z = _z + 5 * Gui::RenderIsland::map_scale;
    float distance = sqrt(pow(_camera.position.x - (_x + 5 * Gui::RenderIsland::map_scale), 2) + pow(_camera.position.z - (_z + 5 * Gui::RenderIsland::map_scale), 2)
        + pow(_camera.position.y - (_y), 2));
    if (distance > 50.0f) {
        if (_camera.position.x < _x + 5.0f * Gui::RenderIsland::map_scale - 20)
            _camera.position.x += distance * GetFrameTime();
        if (_camera.position.x > _x + 5.0f * Gui::RenderIsland::map_scale + 20)
            _camera.position.x -= distance * GetFrameTime();
        if (_camera.position.z < _z + 5.0f * Gui::RenderIsland::map_scale)
            _camera.position.z += distance * GetFrameTime();
        if (_camera.position.z > _z + 5.0f * Gui::RenderIsland::map_scale)
            _camera.position.z -= distance * GetFrameTime();
        if (_camera.position.y < _y - 20)
            _camera.position.y += distance * GetFrameTime();
        if (_camera.position.y > _y + 20)
            _camera.position.y -= distance * GetFrameTime();
    }
    UpdateCamera(&this->_camera, CAMERA_THIRD_PERSON);
}

void Gui::RenderCamera::changeSpectatorMode()
{
    if (IsKeyPressed(KEY_T)) {
        if (!topViewMode) {
            topViewMode = true;
            _camera.position = (Vector3){ (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale - 1, 100.0f, (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale};
            _camera.target = (Vector3){ (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale, 0.0f, (map_dimension.x - 1) / 2.0f * Gui::RenderIsland::map_scale};
            _camera.fovy = Gui::RenderIsland::map_scale * 10.0f;
            _camera.projection = CAMERA_ORTHOGRAPHIC;
        } else {
            topViewMode = false;
            this->_camera.position = (Vector3){ 0.0, 10.0, 0.0 };
            this->_camera.target = (Vector3){ 50.0, 0.0, 50.0 };
            _camera.fovy = 90.0f;
            _camera.projection = CAMERA_PERSPECTIVE;
        }
    }
}

void Gui::RenderCamera::update(int state)
{
    if (Gui::RenderEndGame::_isEndGame) {
        endGameMode();
        return;
    }

    changeSpectatorMode();

    if (state == IN_MENU && state == IN_SETTINGS)
        return;
    if (state == IN_PLAYER_MODE || state == TRY_PLAYER_MODE) {
        playerMode();
        return;
    }
    if (state == IN_SPECTATOR_MODE || state == TRY_SPECTATOR_MODE) {
        if (topViewMode)
            spectatorTopMode();
        else
            spectatorMode();
    }
}