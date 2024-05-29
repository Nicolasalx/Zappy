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
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <raylib.h>
    #include <rlgl.h>
    #include <raymath.h>
    #include <unistd.h>
    #include <iostream>
    #include <string>
    #include <memory>
    #include <vector>
    #include <map>
    #include <functional>
    #include <thread>

    #define MAX_PORT_NB 65535
    #define BUFFER_SIZE 4096
    #define CMD_BUFFER_SIZE 4096
    #define WINDOW_WIDTH 1920 / 2
    #define WINDOW_HEIGHT 1080 / 2
    #define SCALE 6.0f

enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    ISLAND,
    PLAYER
};

struct pos_t {
    float x;
    float y;
};

struct player_t {
    int n;
    pos_t pos;
    pos_t real_pos;
    int level;
    int orientation;
    int real_orientation;
    std::string team_name;
    std::vector<int> inventory;
    int animation_nbr;
    int anim_frame_counter;
};

struct ray_info_t {
    Ray ray;
    BoundingBox box;
    RayCollision collision;
    int type;
    int id;
    int x;
    int y;
};

class TextBox {
    public:
        TextBox(float x, float y, float width, float height, int window_width, int window_height);
        ~TextBox() = default;
        void resize(int window_width, int window_height);
        void add_text(std::string text, float ypos);
        void draw();
    private:
        float _x;
        float _y;
        float _width;
        float _height;
        int _window_width = WINDOW_WIDTH;
        int _window_height = WINDOW_HEIGHT;
        Rectangle _box;
        Color _color;
};

class GameState {
    public:
        GameState();
        ~GameState();
        void parse_server_reply(std::string reply_data);
        void msz(std::vector<std::string> args);
        void bct(std::vector<std::string> args);
        void tna(std::vector<std::string> args);
        void pnw(std::vector<std::string> args);
        void ppo(std::vector<std::string> args);
        void plv(std::vector<std::string> args);
        void pin(std::vector<std::string> args);
        void pdi(std::vector<std::string> args);
        void sgt(std::vector<std::string> args);

        pos_t map_size;
        int time_unit = 0;
        std::map<std::string, std::function<void(std::vector<std::string>)>> cmd_map;
        std::vector<std::vector<std::vector<int>>> object_pos;
        std::vector<player_t> players_list;
        std::vector<std::string> team_names;
};

class Client {
    public:
        Client(int argc, const char **argv);
        ~Client();
        void create_client();
        void init_client_set();
        void launch_client();
        void monitor_input();
        void handle_new_input();
        void handle_new_message();
        void get_args(int argc, const char **argv);
        void check_new_message(std::string reply_data);
        void send_cmd_to_server(char *cmd, int nb_byte);
        void launch_graphic();
    private:
        int fd;
        int max_fd = 0;
        fd_set read_set;
        fd_set write_set;
        unsigned short port;
        struct sockaddr_in server_address;
        std::string cmd_buffer;
        std::string ip;
        GameState gameState;
        std::thread graphic_thread;
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
        void drawLevelPlayerPerTile();

        GameState *gameState;
        Camera3D camera;
        Model sky_box;
        std::vector<Model> model_list;
        std::map<int, int> player_orientation;
        float object_padding[7][2];
        ModelAnimation *player_animation;
        std::vector<TextBox> textBoxs;
        ray_info_t rayInfo;
        // Shader light_shader;
        int window_width = WINDOW_WIDTH;
        int window_height = WINDOW_HEIGHT;
        bool cursor = false;
        float frame_time = 0.0f;
};

#endif /* !ZAPPY_GUI_H_ */
