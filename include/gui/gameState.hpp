/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** gameState
*/

#ifndef GAMESTATE_H_
    #define GAMESTATE_H_

    #include <functional>
    #include <map>
    #include "infoGame.hpp"

namespace Gui
{
    struct incant_t {
        int level;
        pos_t pos;
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
            void pic(std::vector<std::string> args);
            void pie(std::vector<std::string> args);
            void pdi(std::vector<std::string> args);
            void sgt(std::vector<std::string> args);

            // ! maybe private
            pos_t map_size;
            int time_unit = 0;
            double frame_time = 0;
            std::map<std::string, std::function<void(std::vector<std::string>)>> cmd_map;
            // ! maybe public
            std::vector<std::vector<std::vector<int>>> object_pos;
            std::vector<incant_t> incant_list;
            std::vector<player_t> players_list;
            std::vector<std::string> team_names;
    };
}

#endif /* !GAMESTATE_H_ */
