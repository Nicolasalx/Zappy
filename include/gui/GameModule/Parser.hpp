/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include <map>
    #include <functional>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Parser
    {
        public:
            Parser(std::shared_ptr<GameData> gameData);
            ~Parser() = default;
            void msz(std::vector<std::string> args);
            void pdr(const std::vector<std::string> &args);
            void pex(const std::vector<std::string> &args);
            void pfk(const std::vector<std::string> &args);
            void pgt(const std::vector<std::string> &args);
            void sbp(const std::vector<std::string> &args);
            void seg(const std::vector<std::string> &args);
            void sst(const std::vector<std::string> &args);
            void suc(const std::vector<std::string> &args);
            void bct(std::vector<std::string> args);
            void tna(const std::vector<std::string> &args);
            void pnw(std::vector<std::string> args);
            void ppo(std::vector<std::string> args);
            void plv(std::vector<std::string> args);
            void pin(std::vector<std::string> args);
            void pic(std::vector<std::string> args);
            void pie(std::vector<std::string> args);
            void pbc(std::vector<std::string> args);
            void pdi(std::vector<std::string> args);
            void enw(std::vector<std::string> args);
            void ebo(std::vector<std::string> args);
            void edi(std::vector<std::string> args);
            void sgt(std::vector<std::string> args);
            void smg(std::vector<std::string> args);
            void parse_server_reply(std::string reply_data);
            void update(std::vector<std::string> &messRecv);

        private:
            std::shared_ptr<GameData> _gameData;
            std::map<std::string, std::function<void(std::vector<std::string>)>> _cmdMap;
    };
}


#endif /* !PARSER_H_ */
