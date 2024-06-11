/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** SFMLRender
*/

#ifndef SFMLRENDER_HPP_
    #define SFMLRENDER_HPP_

    #include <SFML/Graphics.hpp>
    #include <ARenderModule.hpp>
    #include <SFMLRenderPlayer.hpp>
    #include <SFMLRenderEgg.hpp>
    #include <SFMLRenderMap.hpp>
    #include <SFMLRenderObject.hpp>
    #include <memory>
    #include <vector>

namespace Gui
{
    class SFMLRender : public Gui::ARenderModule
    {
        public:
            SFMLRender();
            ~SFMLRender() override;
 
            Gui::Event getEvent() override;
            void render(const Gui::GameData &gameData) override;

        private:
            sf::RenderWindow window;
            std::unique_ptr<Gui::SFMLRenderPlayer> player;
            std::unique_ptr<Gui::SFMLRenderEgg> egg;
            std::unique_ptr<Gui::SFMLRenderMap> map;
            std::unique_ptr<Gui::SFMLRenderObject> object;

//          Gui::RenderWindow window;
//          Gui::RenderCamera camera;
//          std::unique_ptr<Gui::RenderSkyBox> skyBox;
//          std::unique_ptr<Gui::RenderIsland> island;
//          std::unique_ptr<Gui::RenderObject> object;
//          std::unique_ptr<Gui::RenderParticleSystem> particle;
//          //Gui::RenderMenu menu;
//          std::unique_ptr<Gui::RenderEgg> egg;

            std::vector<std::pair<sf::Keyboard::Key, Gui::EventType>> keyBind = {
                {sf::Keyboard::I, Gui::EventType::KEY_I},
                {sf::Keyboard::O, Gui::EventType::KEY_O},
                {sf::Keyboard::P, Gui::EventType::KEY_P},
                {sf::Keyboard::N, Gui::EventType::NEXT_DISPLAY},
                {sf::Keyboard::M, Gui::EventType::BACK_MENU},
                {sf::Keyboard::R, Gui::EventType::RESTART},
                {sf::Keyboard::Enter, Gui::EventType::ENTER}
            };
            //? Special Event:
            //* Gui::EventType::EXIT
            //! Gui::EventType::LEFT_CLICK
            //! Gui::EventType::WIDOW_RESIZED
    };
}

#endif /* !SFMLRENDER_HPP_ */
