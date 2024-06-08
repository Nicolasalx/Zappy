/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** skyBox
*/

#ifndef RENDERSKYBOX_H_
    #define RENDERSKYBOX_H_

    #include <raylib.h>
    #include <rlgl.h>
    #include "ARayLibModel.hpp"
    #include "GameData.hpp"

namespace Gui
{
    class RenderSkyBox
    {
        public:
            RenderSkyBox();
            ~RenderSkyBox();
            void render();

            Model model;
    };
}

#endif /* !SKYBOX_H_ */
