/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** infoGame
*/

#ifndef INFOGAME_H_
    #define INFOGAME_H_

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096
    #define WINDOW_WIDTH 1920 / 2
    #define WINDOW_HEIGHT 1080 / 2
    #define SCALE 6.0f

    #include <raylib.h>

namespace Gui
{
    struct pos_t {
        float x;
        float y;
    };

    enum {
        FOOD,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME,
        ISLAND,
        PLAYER
    };
    
    enum {
        NO_BUTTON,
        RIGHT_BUTTON,
        LEFT_BUTTON,
        CLOSED_LEFT,
        CLOSED_RIGHT
    };
}

#endif /* !INFOGAME_H_ */
