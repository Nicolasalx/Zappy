/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_client
*/

#include "zappy_gui.hpp"

void Gui::Client::create_client()
{
    this->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->fd == -1) {
        throw my::tracked_exception("Socket creation failed.\n");
    }
    this->server_address.sin_family = AF_INET;
    this->server_address.sin_port = htons(this->port);
    if (connect(this->fd, (struct sockaddr *)
        &this->server_address, sizeof(this->server_address)) != 0) {
        throw my::tracked_exception("Server not found.\n");
    }
}
