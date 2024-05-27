/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "client.hpp"
#include "zappyAi.hpp"
#include "my_tracked_exception.hpp"

void Ai::Client::checkNewMessage(Player &player, const std::string &reply_data)
{
    if (reply_data == "WELCOME\n") {
        std::cout << reply_data;
        this->_isConnected = true;
    }
    if (_isConnected) {
        this->getCmd.parseServerReply(*this, reply_data, player);
    }
}

void Ai::Client::handleNewMessage(Player &player)
{
    char reply_data[BUFFER_SIZE] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(this->fd, &this->readSet)) {
        return;
    }
    size = read(this->fd, &reply_data, sizeof(reply_data));
    if (size == 0) {
        std::cout << "dead" << "\n";
        std::exit(0);
    } else if (size == -1) {
        throw my::tracked_exception("Read failed.\n");
    }
    if (size >= BUFFER_SIZE) {
        std::cout << "Incompatible reply from the server." << std::endl;
        return;
    }
    this->checkNewMessage(player, reply_data);
}
