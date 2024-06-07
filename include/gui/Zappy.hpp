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
    #include "Window.hpp"
    #include "Camera.hpp"
    #include "Object.hpp"
    #include "Menu.hpp"
    #include "Particle.hpp"
    #include "TextBox.hpp"

namespace Gui
{
    class Zappy: virtual public AGameModule
    {
        public:
            Zappy();
            ~Zappy() override;

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event) override;

        private:
            Gui::Window window;
            Gui::Camera camera;
            std::unique_ptr<Gui::SkyBox> skyBox;
            std::unique_ptr<Gui::Island> island;
            std::unique_ptr<Gui::Object> object;
            std::unique_ptr<Gui::Player> player;
            Gui::Menu menu;
            Gui::ParticleSystem particle;
            Gui::TextBox_list textBoxs;
            std::unique_ptr<Gui::Egg> egg;
    };
};

#endif /* !ZAPPY_HPP_ */
