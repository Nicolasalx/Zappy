/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** log
*/

#include "my_log.hpp"

void my::log::info(const std::string &msg,
    std::source_location info)
{
    std::stringstream s;
    s << "\033[1m" << info.file_name() << ":\033[96m" << info.line() << "\033[0;1m: "
        "\033[96minfo: \033[0m" << msg << "\n";
    std::cout << s.str();
}

void my::log::warning(const std::string &msg,
    std::source_location info)
{
    std::stringstream s;
    s << "\033[1m" << info.file_name() << ":\033[96m" << info.line() << "\033[0;1m: "
        "\033[95mwarning: \033[0m" << msg << "\n";
    std::cout << s.str();
}

void my::log::error(const std::string &msg,
    std::source_location info)
{
    std::stringstream s;
    s << "\033[1m" << info.file_name() << ":\033[96m" << info.line() << "\033[0;1m: "
        "\033[91merror: \033[0m" << msg << "\n";
    std::cout << s.str();
}
