/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_input
*/

#include "client.hpp"
#include "zappyAi.hpp"

static void handleCtrlD(ssize_t nb_byte) // ! Why this function is not in the class ?
{
    if (nb_byte == 0) {
        std::exit(0);
    }
}

void Ai::Client::handleNewInput()
{
    char command[BUFFER_SIZE] = {0};
    ssize_t nb_byte = 0;

    if (FD_ISSET(STDIN_FILENO, &this->readSet)) {
        nb_byte = read(STDIN_FILENO, command, BUFFER_SIZE);
        handleCtrlD(nb_byte);
        sendCmdToServer(command, nb_byte);
    }
}
