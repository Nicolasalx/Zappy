/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_H_
    #define IGAMEMODULE_H_

    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class IGameModule
    {
        public:
            virtual ~IGameModule() = default;

            virtual const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event) = 0;
    };
}

#endif /* !IGAMEMODULE_H_ */
