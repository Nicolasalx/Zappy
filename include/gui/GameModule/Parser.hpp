/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include "GameData.hpp"
    #include "Zappy.hpp"

namespace Gui {
    class Parser {
        public:
            Parser(std::shared_ptr<GameData> gameData);
            ~Parser();
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
            void enw(std::vector<std::string> args);
            void ebo(std::vector<std::string> args);
            void edi(std::vector<std::string> args);
            void sgt(std::vector<std::string> args);
            void smg(std::vector<std::string> args);

        private:
            std::shared_ptr<GameData> _gameData;
            std::map<std::string, std::function<void(std::vector<std::string>)>> _cmdMap;
    };
}


#endif /* !PARSER_H_ */
