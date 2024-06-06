/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Zappy
*/

#ifndef ZAPPY_HPP_
    #define ZAPPY_HPP_

    #include "SkyBox.hpp"
    #include "Island.hpp"
    #include "Player.hpp"
    #include "AGameModule.hpp"

namespace Gui
{
    class Zappy: public AGameModule
    {
        public:
            Zappy();
            ~Zappy() override;

            const Gui::GameData &update(const Gui::Event &event) override;

        private:
            SkyBox _skybox;
            Island _island;
            Player _player;
    };
};

#endif /* !ZAPPY_HPP_ */
