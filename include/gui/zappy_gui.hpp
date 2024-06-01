/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** zappy_gui.hpp
*/

#ifndef ZAPPY_GUI_H_
    #define ZAPPY_GUI_H_

    #include "my_tracked_exception.hpp"
    #include "my_log.hpp"

    #include <unistd.h>
    #include <iostream>
    #include <string>
    #include <memory>
    #include <vector>
    #include <map>
    #include <functional>

    #include "gameState.hpp"
    #include "textBox.hpp"
    #include "infoGame.hpp"
    #include "particle.hpp"
    #include "camera.hpp"
    #include <list>
    #include "window.hpp"
    #include "skyBox.hpp"
    #include "island.hpp"
    #include "object.hpp"
    #include "player.hpp"
    #include "menu.hpp"

namespace Gui
{
    class Graphic {
        public:
        Graphic(std::shared_ptr<GameState> gameState);
        ~Graphic();

        void init_lighting();
        void init_2D();
        void set_fps(int fps);

        //loop
        void loop();

        //event
        void event();
        void change_cursor();
        void window_resize();
        void click_event();
        void change_player_selected();

        //draw
        void draw_3D();
        void draw_2D();
        void draw_sky_box();
        void draw_general_info();
        void draw_player_info();
        void draw_tile_info();
        void draw_all_player_level();

        std::shared_ptr<GameState> _gameState;
        Gui::Window window;
        Gui::Camera camera;
        Gui::SkyBox skyBox;
        Gui::Object object;
        Gui::Island island;
        Gui::Player player;
        Gui::Menu menu;
        Gui::ParticleSystem particle;

        std::vector<TextBox> textBoxs;
        ray_info_t rayInfo;
        Shader light_shader;
        bool cursor = false;
        std::vector<int> listLevelPlayer;
        Texture2D particle_texture;
    };
}

#endif /* !ZAPPY_GUI_H_ */
