/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "IClient.hpp"
    #include <memory>
    #include <vector>
    #include "GameData.hpp"
    #include "Event.hpp"

namespace Gui
{
    class Menu
    {
        public:
            Menu(std::shared_ptr<Gui::GameData> gameData);
            ~Menu() = default;

            void update(const Gui::Event &event);

        private:
            void componentPlay();
            void componentSettings();
            void componentPlayerMode();
            void componentSpectatorMode();
            void componentQuit();

            void inputBoxIP();
            void inputBoxPort();

            void announceRetry();
            void goBackToTheMenu();

            void changeScreenMenu();

            void addBox(const Box &box, const std::string &contentText);
            void addText(const Text &text);
            void addComponent(ComponentType cmpType);
            void handleEvent(const Gui::Event &event);
            bool isMouseOnBox(const Box &box, const Pos &mousePos);
            void checkMouseState(const Gui::Event &event, Component &component);
            void resize(const Gui::Event &event);

            std::shared_ptr<Gui::GameData> _gameData;

            ComponentType _cmpSelectionned = NONE;

            int _windowWidth = 0;
            int _windowHeight = 0;

            char name[9 + 1] = "\0";
            int letterCount = 0;

            Component _component;
    };
}

#endif /* !MENU_H_ */
