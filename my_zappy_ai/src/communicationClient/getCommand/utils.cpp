/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** utils
*/

#include "zappyAi.hpp"

std::string Ai::GetCommand::extractContentBetweenBrackets(const std::string &input)
{
    size_t start = input.find('[');
    if (start == std::string::npos) {
        return "";
    }
    size_t end = input.find(']', start);
    if (end == std::string::npos) {
        return "";
    }
    return input.substr(start + 1, end - start - 1);
}
