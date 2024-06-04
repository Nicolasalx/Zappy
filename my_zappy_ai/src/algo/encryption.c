/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** encryption
*/

#include "zappy_ai.h"

char *encrypt_message(char *message, char key)
{
    int len = strlen(message);
    char *encrypted_message = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        encrypted_message[i] = message[i] ^ key;
    }
    encrypted_message[len] = '\0';
    return encrypted_message;
}
