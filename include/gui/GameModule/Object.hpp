/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Object
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

    #include "Zappy.hpp"

namespace Gui
{
    class Object: public Gui::Zappy
    {
        public:
            Object();
            ~Object() override;

            const Gui::GameData &update(std::shared_ptr<Gui::IClient> &client, std::vector<std::string> &messRecv, const Gui::Event &event) override;

        private:
    
    };
}

#endif /* !OBJECT_H_ */
