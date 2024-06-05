/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** encryption
*/

#include "zappy_ai.h"

void encrypt_message(char *message, char key)
{
    for (size_t i = 0; message[i] != '\0'; ++i) {
        message[i] ^= key;
    }
}
