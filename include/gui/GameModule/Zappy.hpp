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
    #include "Egg.hpp"
    #include "Particle.hpp"
    #include "TextBox.hpp"
    #include "Parser.hpp"
    #include "Client.hpp"
    #include <memory>
    #include "Event.hpp"
    #include "PlayerParser.hpp"
    #include "PlayerMode.hpp"

namespace Gui
{
    class Zappy : virtual public AGameModule
    {
        public:
            Zappy(std::shared_ptr<Gui::IClient> client, std::shared_ptr<Gui::GameData> gameData);
            ~Zappy() override = default;

            void update(std::vector<std::string> &messRecv, const Gui::Event &event) override;

        private:
            std::shared_ptr<Gui::IClient> _client;

            Gui::Parser _parser;
            Gui::PlayerParser _playerParser;
            Gui::Island _island;
            Gui::Object _object;
            Gui::Player _player;
            Gui::Egg _egg;
            Gui::TextBox _textBox;
            Gui::Menu _menu;
            Gui::PlayerMode _playerMode;
    };
};

#endif /* !ZAPPY_HPP_ */
