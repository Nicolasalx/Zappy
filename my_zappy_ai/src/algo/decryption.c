/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** decryption
*/

#include "zappy_ai.h"

char *decrypt_message(const char *message, char key)
{
    int len = strlen(message);
    char *decrypted_message = malloc(len + 1);

    for (size_t i = 0; i < len; i++) {
        decrypted_message[i] = message[i] ^ key;
    }
    decrypted_message[len] = '\0';
    return decrypted_message;
}
