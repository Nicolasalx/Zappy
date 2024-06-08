/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** client
*/

#include "Client.hpp"

extern "C"
{
    Gui::IClient *entryPoint(void)
    {
        return new Gui::Client();
    }
}

Gui::Client::Client()
    : io_context_(), resolver_(io_context_), socket_(io_context_)
{
}

Gui::Client::~Client()
{
    if (socket_.is_open()) {
        socket_.close();
    }
}

void Gui::Client::connect(const std::string &ip, const std::string &port)
{
    endpoint_ = asio::ip::tcp::resolver::results_type(resolver_.resolve(ip, port));
    asio::connect(socket_, endpoint_);
}

void Gui::Client::send(const std::string &message)
{
    asio::write(socket_, asio::buffer(message));
}

void Gui::Client::bufferisingReply(std::string reply, std::vector<std::string> &message)
{
    std::size_t start = 0;
    std::size_t pos = 0;

    if (!buffer_.empty()) {
        reply = buffer_ + reply;
    }
    pos = reply.find('\n');
    while (pos != std::string::npos) {
        message.push_back(reply.substr(start, pos - start + 1));
        start = pos + 1;
        pos = reply.find('\n', start);
    }
    if (start < reply.length()) {
        buffer_ = reply.substr(start);
    } else {
        buffer_.clear();
    }
}

std::vector<std::string> Gui::Client::recv()
{
    std::vector<std::string> message;
    char data[buffer_size_ + 1] = {0};
    std::size_t length = 0;

    if (socket_.available() <= 0) {
        return std::vector<std::string>();
    }
    length = socket_.read_some(asio::buffer(data, buffer_size_));
    bufferisingReply(std::string(data, length), message);
    return message;
}
