/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** endOfGame
*/

#include "RenderEndGame.hpp"
#include "RenderIsland.hpp"

bool Gui::RenderEndGame::_isEndGame = false;
bool Gui::RenderEndGame::_isGameFinished = false;

Gui::RenderEndGame::RenderEndGame()
{
    addModel(Gui::SPACESHIP_MODEL.data());
    x = 7.0f;
    y = 300.0f;
    z = 1000.0f;
}

void Gui::RenderEndGame::render(const GameData &gameData)
{
    if (gameData.rayInfo.type == 1)
        _isEndGame = true;
    
    if (!_isEndGame && !_isGameFinished)
        return;

    if (y >= 2 && this->_timer == 0) {
        y -= y * (gameData.frameTime * 0.7f);
        z -= z * (gameData.frameTime * 0.7f);
    } else {
        this->_timer += gameData.frameTime;
    }
    if (this->_timer > 9.5f) {
        z -= gameData.frameTime * 2000;
        y += gameData.frameTime * 200;
        Gui::RenderEndGame::_isEndGame = false;
        Gui::RenderEndGame::_isGameFinished = true;
    } else if (this->_timer > 4.0f) {
        y += gameData.frameTime * 8;
        z -= gameData.frameTime * 10;
    }

    drawModel((ModelInfo){0, (Vector3){x + 5.0f * Gui::RenderIsland::map_scale , y, z + 5.0f * Gui::RenderIsland::map_scale}, (Vector3){0, 0, 0}, 0, (Vector3){7.0f, 7.0f, 7.0f}, WHITE});
    
}