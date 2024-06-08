/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Object
    {
        public:
            Object(std::shared_ptr<Gui::GameData> gameData);
            ~Object() = default;

            void update(const Gui::Event &event);

        private:
            std::shared_ptr<Gui::GameData> _gameData;

    };
}

#endif /* !OBJECT_H_ */
