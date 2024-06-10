/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_H_
    #define AGAMEMODULE_H_

    #include "IGameModule.hpp"
    #include "GameData.hpp"

namespace Gui
{
    class AGameModule: public Gui::IGameModule
    {
        public:
            ~AGameModule() override = default;

        protected:
            std::shared_ptr<Gui::GameData> _gameData;
    };
}

#endif /* !AGAMEMODULE_H_ */
