/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SkyBox
*/

#ifndef SKYBOX_HPP_
    #define SKYBOX_HPP_

    #include "AGameModule.hpp"

namespace Gui
{
    class SkyBox: public Gui::AGameModule
    {
        public:
            SkyBox();
            ~SkyBox() override;

            const Gui::GameData &update(const Gui::Event &event) override;

        private:
    
    };
}

#endif /* !SKYBOX_H_ */
