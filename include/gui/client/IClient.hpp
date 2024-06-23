/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** IClient
*/

#ifndef ICLIENT_HPP_
    #define ICLIENT_HPP_

    #include <vector>
    #include <string>

namespace Gui
{
    class IClient
    {
    public:
        virtual ~IClient() = default;

        virtual void connect(const std::string &ip, const std::string &port) = 0;
        virtual void disconnect() = 0;
        virtual void send(const std::string &message) = 0;
        virtual std::vector<std::string> recv() = 0;
    };
}

#endif /* !ICLIENT_HPP_ */
