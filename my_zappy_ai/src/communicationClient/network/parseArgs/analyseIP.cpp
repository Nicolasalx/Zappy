/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myftp-thibaud.cathala
** File description:
** analyseIP
*/

#include "client.hpp"
#include "my_tracked_exception.hpp"

void Ai::Client::analyseIP(int argc, const char **argv, int index)
{
    std::string nextArg = getNextArg(argc, argv, index);

    if (isValidIP(nextArg)) {
        this->ip = nextArg;
    } else if (nextArg == "localhost") {
        this->ip = "127.0.0.1";
    } else {
        throw my::tracked_exception("Invalid IP gived\n");
    }
}

bool Ai::Client::isValidIPv4(const std::string &str)
{
    const std::regex ipv4Pattern(
        R"(^(\d{1,3}\.){3}\d{1,3}$)"
    );
    if (!std::regex_match(str, ipv4Pattern)) {
        return false;
    }
    std::stringstream s(str);
    std::string segment;
    while (std::getline(s, segment, '.')) {
        if (std::stoi(segment) > 255) {
            return false;
        }
    }
    return true;
}

bool Ai::Client::isValidIPv6(const std::string &str)
{
    const std::regex ipv6Pattern(
        R"(^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$)"
    );
    return std::regex_match(str, ipv6Pattern);
}

bool Ai::Client::isValidIP(const std::string &str)
{
    return isValidIPv4(str) || isValidIPv6(str);
}
