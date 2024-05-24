/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** create_client
*/

#include "zappyAi.hpp"

void Ai::Client::createClient()
{
    this->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->fd == -1) {
        throw my::tracked_exception("Socket creation failed.\n");
    }
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_port = htons(this->port);
    if (connect(this->fd, (struct sockaddr *)
        &this->serverAddress, sizeof(this->serverAddress)) != 0) {
        throw my::tracked_exception("Server not found.\n");
    }
}
