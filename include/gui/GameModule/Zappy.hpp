/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Zappy
*/

#ifndef ZAPPY_HPP_
    #define ZAPPY_HPP_

    #include "GameData.hpp"
    #include "Island.hpp"
    #include "Player.hpp"
    #include "AGameModule.hpp"
    #include "Object.hpp"
    #include "Menu.hpp"
    #include "Particle.hpp"
    #include "TextBox.hpp"
    #include "Parser.hpp"
    #include "Client.hpp"
    #include <memory>

namespace Gui
{
    class Zappy: virtual public AGameModule
    {
        public:
            Zappy(std::shared_ptr<Gui::IClient> client);
            ~Zappy() override;

            const Gui::GameData &update(std::vector<std::string> &messRecv, const Gui::Event &event) override;

        private:
            std::shared_ptr<Gui::IClient> _client;

            Gui::Parser parser;
            std::unique_ptr<Gui::Island> island;
            std::unique_ptr<Gui::Object> object;
            std::unique_ptr<Gui::Player> player;
            std::unique_ptr<Gui::Egg> egg;
    };
};

#endif /* !ZAPPY_HPP_ */
