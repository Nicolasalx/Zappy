/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** ARenderModule
*/

#ifndef ARENDERMODULE_HPP_
    #define ARENDERMODULE_HPP_

    #include "GameData.hpp"
    #include "IRenderModule.hpp"

namespace Gui
{
    class ARenderModule : virtual public IRenderModule
    {
        protected:
            bool _ignoreKey = false;
    };
}

#endif