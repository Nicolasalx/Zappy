/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include "IClient.hpp"
    #include <asio.hpp>

namespace Gui
{
    class Client : public virtual Gui::IClient
    {
    private:
        asio::io_context io_context_;
        asio::ip::tcp::resolver resolver_;
        asio::ip::tcp::resolver::results_type endpoint_;
        asio::ip::tcp::socket socket_;

        std::string buffer_;
        static constexpr std::size_t buffer_size_ = 4096;

        void bufferisingReply(std::string reply, std::vector<std::string> &message);

    public:
        Client();
        ~Client() override;

        void connect(const std::string &ip, const std::string &port) override;
        void send(const std::string &message) override;
        std::vector<std::string> recv() override;
    };
}

#endif /* !CLIENT_HPP_ */
