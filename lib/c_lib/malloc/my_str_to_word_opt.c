/*
** EPITECH PROJECT, 2024
** my_str_to_word_opt
** File description:
** my_str_to_word_opt
*/

#include <stdlib.h>
#include "my_malloc.h"
#include "my_string.h"

int count_nb_word_opt(const char *str, const char *delimiter)
{
    int count_word = 1;
    bool is_delimiter;

    for (int i = 0; str[i] != '\0'; ++i) {
        is_delimiter = is_in_str(str[i], delimiter);
        if (is_delimiter) {
            ++count_word;
        }
    }
    return count_word;
}

int *count_size_word_opt(const char *str, const char *delimiter, int nb_word)
{
    int *size_word = malloc(sizeof(int) * nb_word);
    int count_size_word = 0;
    int index = 0;
    bool is_delimiter = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        is_delimiter = is_in_str(str[i], delimiter);
        if (is_delimiter) {
            size_word[index] = count_size_word;
            ++ index;
            count_size_word = 0;
        } else {
            ++count_size_word;
        }
    }
    size_word[index] = count_size_word;
    return size_word;
}

char **my_str_to_word_opt(const char *str, const char *delimiter,
    int nb_word, const int *size_word)
{
    char **word = malloc_adv_board(nb_word, size_word);
    int i_index = 0;
    int j_index = 0;
    bool is_delimiter = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        is_delimiter = is_in_str(str[i], delimiter);
        if (is_delimiter) {
            ++ i_index;
            j_index = 0;
        } else {
            word[i_index][j_index] = str[i];
            ++ j_index;
        }
    }
    return word;
}