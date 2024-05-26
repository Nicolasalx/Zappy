/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** utils
*/

#include "client.hpp"
#include "my_tracked_exception.hpp"

std::string Ai::Client::getNextArg(int argc, const char **argv, int i)
{
    if (i + 1 >= argc) {
        throw my::tracked_exception("The argument after the flag had not been gived.\n");
    }
    return argv[i + 1];
}

bool Ai::Client::charIsInStr(char c, const std::string &strToAnalyze)
{
    for (const auto &chr: strToAnalyze) {
        if (c == chr) {
            return true;
        }
    }
    return false;
}

int Ai::Client::getInt(const std::string &str)
{
    for (const auto &chr: str) {
        if (!charIsInStr(chr, "0123456789")) {
            throw my::tracked_exception("Argument gived need to be a int.\n");
        }
    }
    return std::stoi(str);
}
