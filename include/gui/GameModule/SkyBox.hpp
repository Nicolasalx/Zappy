/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SkyBox
*/

#ifndef SKYBOX_HPP_
    #define SKYBOX_HPP_

    #include "Zappy.hpp"
    #include <raylib.h>

namespace Gui
{
    struct SkyBox {
        std::string vsFileName;
        std::string fsFileName;
        std::string fileNameImage;
    };
    class SkyBox
    {
        public:
            SkyBox();
            ~SkyBox() override;

            const Gui::GameData &update(Gui::SkyBox &skybox) override;

        private:

    };
}

#endif /* !SKYBOX_H_ */
