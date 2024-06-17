/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "IClient.hpp"
    #include "GameData.hpp"
    #include "Event.hpp"
    #include <memory>
    #include <map>
    #include <vector>

namespace Gui
{
    class Menu
    {
        public:
            Menu(std::shared_ptr<Gui::GameData> gameData);
            ~Menu() = default;

            void update(const Gui::Event &event);
            static bool isMousePressed(const Gui::Event &event);
            static bool isMouseOnBox(const Box &box, const Pos &mousePos);

        private:
            void componentPlay();
            void componentSettings();
            void componentPlayerMode();
            void componentSpectatorMode();
            void componentQuit();
            void addTriangle(Pos startPosTriangleLeft, ComponentType cmpType);

            void textSettings();

            void inputBoxIP();
            void inputBoxPort();

            void announceRetry();
            void goBackToTheMenu();

            void changeScreenMenu();

            void screenMenu();
            void screenSettings();
            void screenConnectionFailed();


            void handleEventSettings(Component &component, const Gui::Event &event);

            void addBox(const Box &box, const std::string &contentText);
            void addText(const Text &text);
            void addComponent(ComponentType cmpType);
            void handleEvent(const Gui::Event &event);
            void checkMouseState(const Gui::Event &event, Component &component);
            void resize(const Gui::Event &event);

            Pos resizePosition(const Pos position, const Gui::Event &event);

            std::shared_ptr<Gui::GameData> _gameData;

            ComponentType _cmpSelectionned = NONE;

            int _windowWidth = 0;
            int _windowHeight = 0;

            char name[9 + 1] = "\0";
            int letterCount = 0;

            Component _component;

            StateGame _oldState = IN_MENU;

            std::vector<OptionResolution> _optionResolution = {
                {"1920x1080", {1920, 1080}},
                {"1280x720", {1280, 720}},
                {"720x480", {720, 480}}
            };
            int _idxOptionResolution = 0;
    };
}

#endif /* !MENU_H_ */
