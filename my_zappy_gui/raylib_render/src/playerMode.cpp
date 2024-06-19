/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description
** playerMode
*/

#include "RenderPlayerMode.hpp"
#include "RenderColor.hpp"

void Gui::RenderPlayerMode::render(const GameData &gameData)
{
    if (gameData.dataMenu.stateGame != IN_PLAYER_MODE && gameData.dataMenu.stateGame != TRY_PLAYER_MODE) {
        return;
    }
    for (const auto &button: gameData.playerMode.buttonPlayerMode) {
        Color colorButton = Gui::RenderColor::getColorFromGame(button.button.color);
        Rectangle box = Rectangle(button.button.pos.x, button.button.pos.y, button.button.size.width, button.button.size.height);

        colorButton.a = 100;
        DrawRectangleRec(box, colorButton);
        colorButton.a = 255;
        DrawRectangleLinesEx(box, 1, colorButton);
        DrawText(button.text.contentText.c_str(), button.text.pos.x, button.text.pos.y, button.text.fontSize, Gui::RenderColor::getColorFromGame(button.text.color));
    }
}
