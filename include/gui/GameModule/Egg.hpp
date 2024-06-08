/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui {
    class Egg {
        public:
            Egg(std::shared_ptr<GameData> gameData);
            ~Egg() = default;
            void update(const Gui::Event &event);

        private:
            std::shared_ptr<GameData> _gameData;
    };
}

#endif /* !EGG_H_ */