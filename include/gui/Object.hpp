/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include "AGameModule.hpp"

namespace Gui
{
    class Object: public Gui::AGameModule
    {
        public:
            Object();
            ~Object() override;
    
            const Gui::GameData &update(const Gui::Event &event) override;
    
        private:
    
    };
}

#endif /* !OBJECT_H_ */
