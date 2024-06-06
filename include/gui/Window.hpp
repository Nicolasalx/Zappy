/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include "AGameModule.hpp"
    #include "GameData.hpp"

namespace Gui
{
    class Window: public Gui::AGameModule
    {
        public:
            Window();
            ~Window() override;

            const Gui::GameData &update(const Gui::Event &event) override;

        private:
    
    };
}

#endif /* !WINDOW_H_ */
