/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include "gameState.hpp"
    #include <memory>
    #include <vector>

namespace Gui
{
    enum ComponentType {
        NONE,
        SETTINGS,
        PLAY,
        QUIT
    };

    struct InfoBox {
        float x;
        float y;
        float width;
        float height;
        int windowWidth;
        int windowHeight;
    };

    struct Pos {
        float x;
        float y;
    };

    struct InfoComponent {
        InfoBox infoBox;
        Pos posText;
    };

    struct Text {
        std::string contentText;
        pos_t pos;
        int fontSize;
        Color color;
    };

    struct Box {
        Rectangle rect;
        Color color;
    };

    struct Component {
        Box box;
        Text text;

        InfoComponent infoCmp;
        ComponentType cmpType;
    };

    class Menu {
        public:
            Menu(std::shared_ptr<GameState> gameState, int window_width, int window_height);
            ~Menu() = default;

            void renderMenu();
            void handleEventMenu();
            void resizeMenu(int window_width, int window_height);

            void render(Component &component);

            void componentPlay();
            void componentSettings();
            void componentQuit();

            void handleEventEachComponent(Gui::Component &component);

            void addBox(const InfoBox &infoBox, Color color);
            void addText(const Text &text);
            void addComponent(ComponentType cmpType);

            bool isInMenu = true;
        private:
            std::shared_ptr<GameState> _gameState;

            std::vector<Gui::Component> _componentList;

            int window_width = 0;
            int window_height = 0;

            Component _component;
    };
}

#endif /* !MENU_H_ */
