/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include <functional>
    #include <map>

namespace Gui
{
    struct pos {
        float x;
        float y;
    };

    struct incant {
        int level;
        pos pos;
    };

    struct egg {
        int player_number;
        int egg_number;       
        pos pos;
    };

    struct player {
        int n;
        pos pos;
        pos real_pos;
        int level;
        int orientation;
        int real_orientation;
        std::string team_name;
        std::vector<int> inventory;
        int animation_nbr;
        int anim_frame_counter;
    };

    struct GameData
    {
        pos map_size;
        int time_unit = 0;
        double frame_time = 0;
        std::vector<egg> eggs_list;
        std::vector<incant> incant_list;
        std::vector<player> players_list;
        std::vector<std::string> team_names;
        std::vector<std::string> server_resp;
        std::vector<std::vector<std::vector<int>>> object_pos;
    };
}

#endif /* !GAMEDATA_HPP_ */
