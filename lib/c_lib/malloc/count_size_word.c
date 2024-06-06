/*
** EPITECH PROJECT, 2024
** count_size_word
** File description:
** count_size_word
*/

#include "my_string.h"
#include "my_malloc.h"

static void count_size_word_helper(int *size_word,
    int count_size_word, bool end_word, int index)
{
    if (end_word) {
        size_word[index] = count_size_word;
    }
}

int *count_size_word(const char *str, const char *delimiter, int nb_word)
{
    int *size_word = malloc_array(nb_word);
    int count_size_word = 0;
    bool end_word = false;
    int index = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_in_str(str[i], delimiter) == false) {
            ++ count_size_word;
            end_word = true;
            continue;
        }
        if (end_word) {
            end_word = false;
            size_word[index] = count_size_word;
            ++ index;
            count_size_word = 0;
        }
    }
    count_size_word_helper(size_word, count_size_word, end_word, index);
    return size_word;
}
