/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_error
*/

#include "my_error.h"
#include <stdio.h>

void my_error(char *error, int exit_value)
{
    printf("%s\n", error);
    my_exit(exit_value);
}
