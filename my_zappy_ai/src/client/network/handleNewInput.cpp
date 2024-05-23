/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** handle_new_input
*/

#include "zappy_ai.hpp"

// static void execute_command(std::string command)
// {
//     send_cmd_to_server(command);
// }

// static void buffering_input(client_t *client, char *command, ssize_t nb_byte)
// {
//     char *start_cmd = command;
//     char *end_cmd = strchr(command, '\n');

//     while (end_cmd != NULL) {
//         strncat(client->cmd_buffer, command, (end_cmd + 1) - start_cmd);
//         execute_command(client, client->cmd_buffer);
//         if (client->cmd_buffer == NULL) {
//             return;
//         }
//         memset(client->cmd_buffer, 0, CMD_BUFFER_SIZE);
//         memmove(start_cmd, end_cmd + 1, strlen(end_cmd + 1) + 1);
//         end_cmd = strchr(command, '\n');
//     }
//     strncat(client->cmd_buffer, start_cmd, nb_byte);
// }

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
        // bufferize here (an action is request here ?)
        sendCmdToServer(command, nb_byte);
    }
}
