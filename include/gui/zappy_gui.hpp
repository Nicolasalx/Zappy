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
    #include "skybox.hpp"
    #include "island.hpp"
    #include "object.hpp"
    #include "player.hpp"
    #include "menu.hpp"

namespace Gui
{
    class Graphic {
        public:
        Graphic(GameState *gameState);
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
        void update_animation(player_t &player);
        void update_player_pos(player_t &player);
        void click_event();
        void change_player_selected();
        void update_particle_list();

        //draw
        void draw_3D();
        void draw_2D();
        void draw_sky_box();
        void draw_object();
        void draw_map();
        void draw_player();
        void draw_general_info();
        void draw_player_info();
        void draw_tile_info();
        void draw_all_player_level();
        void draw_particle();

        Gui::Window window;
        GameState *gameState;
        Gui::Camera camera;
        Gui::SkyBox skyBox;
        std::vector<Model> _modelList;
        Gui::Object object;
        Gui::Island island;
        Gui::Player player;
        Gui::Menu menu;

        std::vector<TextBox> textBoxs;
        std::vector<ParticleSystem> particle_systems;
        ray_info_t rayInfo;
        Shader light_shader;
        bool cursor = false;
        float frame_time = 0.0f;
        std::vector<int> listLevelPlayer;
        Texture2D particle_texture;
    };
}

#endif /* !ZAPPY_GUI_H_ */
