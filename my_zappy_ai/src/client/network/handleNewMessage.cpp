/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "zappy_ai.hpp"

void Ai::Client::checkNewMessage(std::string reply_data)
{
    if (reply_data == "WELCOME\n") {
        dprintf(this->fd, "GRAPHIC\n");
    } else {
        //this->gameState.parse_server_reply(reply_data); // ! Change
    }
}

void Ai::Client::handleNewMessage()
{
    char reply_data[BUFFER_SIZE] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(this->fd, &this->readSet)) {
        return;
    }
    size = read(this->fd, &reply_data, sizeof(reply_data));
    if (size == 0) {
        std::cout << "Server closed." << std::endl;
        std::exit(0);
    } else if (size == -1) {
        throw my::tracked_exception("Read failed.\n");
    }
    if (size >= BUFFER_SIZE) {
        std::cout << "Incompatible reply from the server." << std::endl;
        return;
    }
    this->checkNewMessage(reply_data);
}
