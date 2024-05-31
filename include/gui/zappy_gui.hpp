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
    #include <list>

namespace Gui
{
    class ParticleSystem {
        public:
            ParticleSystem();
            ~ParticleSystem() = default;
            void update_particle();
            void draw();

            pos_t pos;
            std::list<float> particles;
            size_t max_particles;
            float velocity;
    };

    class Graphic {
        public:
        Graphic(GameState *gameState);
        ~Graphic();
        //init
        void init_window();
        void init_camera();
        void init_sky_box();
        void init_island();
        void init_player();
        void init_object();
        void init_object_padding();
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

        GameState *gameState;
        Camera3D camera;
        Model sky_box;
        std::vector<Model> model_list;
        std::map<int, int> player_orientation;
        float object_padding[7][2];
        ModelAnimation *player_animation;
        std::vector<TextBox> textBoxs;
        std::vector<ParticleSystem> particle_systems;
        ray_info_t rayInfo;
        // Shader light_shader;
        int window_width = WINDOW_WIDTH;
        int window_height = WINDOW_HEIGHT;
        bool cursor = false;
        float frame_time = 0.0f;
        std::vector<int> listLevelPlayer;
    };
}

#endif /* !ZAPPY_GUI_H_ */
