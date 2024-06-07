/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** skyBox
*/

#ifndef RENDERSKYBOX_H_
    #define RENDERSKYBOX_H_

    #include "RayLibObject.hpp"
    #include "GameData.hpp"

namespace Gui
{
    class RenderSkyBox
    {
        public:
            RenderSkyBox();
            ~RenderSkyBox() = default;
            void render(const GameData &gameData);
            Model model;

        private:
            Gui::GameData _gameData;
    };
}

#endif /* !SKYBOX_H_ */
