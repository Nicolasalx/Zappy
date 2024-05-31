/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** send_cmd_to_server
*/

#include "zappy_gui.hpp"

void Gui::Client::send_cmd_to_server(char *cmd, int nb_byte)
{
    if (FD_ISSET(this->fd, &this->write_set)) {
        if (send(this->fd, cmd, nb_byte, 0) == -1) {
            std::cout << "Fail to send message to server.\n";
        }
    }
}
