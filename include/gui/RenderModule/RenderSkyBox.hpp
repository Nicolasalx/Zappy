/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** skyBox
*/

#ifndef RENDERSKYBOX_H_
    #define RENDERSKYBOX_H_

    #include "RayLibObject.hpp"

namespace Gui
{
    class RenderSkyBox : public virtual RaylibObject {
        public:
            RenderSkyBox();
            ~RenderSkyBox() = default;
            void render();
            Model model;

        private:
    };
}

#endif /* !SKYBOX_H_ */
