/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_message
*/

#include "client.hpp"

void Gui::Client::check_new_message(std::string reply_data)
{
    if (reply_data == "WELCOME\n") {
        char graphic_cmd[9] = "GRAPHIC\n";
        this->send_cmd_to_server(graphic_cmd, 8);
    } else {
        this->gameState.parse_server_reply(reply_data);
    }
}

void Gui::Client::handle_new_message()
{
    char reply_data[BUFFER_SIZE] = {0};
    ssize_t size = 0;

    if (!FD_ISSET(this->fd, &this->read_set)) {
        return;
    }
    size = read(this->fd, &reply_data, sizeof(reply_data) - 1);
    if (size == 0) {
        std::cout << "Server closed.\n";
        exit(0);
    } else if (size == -1) {
        throw my::tracked_exception("Read failed.\n");
    }
    if (size >= BUFFER_SIZE) {
        std::cout << "Incompatible reply from the server.\n";
        return;
    }
    this->check_new_message(reply_data);
}
