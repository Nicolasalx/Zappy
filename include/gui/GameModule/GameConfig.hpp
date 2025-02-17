/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** GameConfig
*/

#ifndef GAMECONFIG_HPP_
    #define GAMECONFIG_HPP_

    #include <string>

namespace Gui
{
    constexpr std::string_view EGG_MODEL = "bonus/assets/egg.obj";
    constexpr std::string_view EGG_TEXTURE = "bonus/assets/texture_egg.png";

    constexpr std::string_view SKYBOX_VERTEX_SHADER = "bonus/assets/skybox.vs";
    constexpr std::string_view SKYBOX_FRAGMENT_SHADER = "bonus/assets/skybox.fs";
    constexpr std::string_view SKYBOX_TEXTURE = "bonus/assets/skybox3.png";

    constexpr std::string_view PLAYER_MODEL = "bonus/assets/Astronaut.iqm";
    constexpr std::string_view PLAYER_TEXTURE = "bonus/assets/AstronautColor.png";

    constexpr std::string_view EARTH_MODEL = "bonus/assets/earth.obj";
    constexpr std::string_view EARTH_TEXTURE = "bonus/assets/texture_earth.png";
    constexpr std::string_view CLOUD_TEXTURE = "bonus/assets/texture_cloud.png";
    constexpr std::string_view MENU_ISLAND = "bonus/assets/menu_island.png";

    constexpr std::string_view ISLAND_MODEL = "bonus/assets/new_island3.gltf";
    constexpr std::string_view ISLAND_LOW_POLY = "bonus/assets/new_island_low_poly1.gltf";
    constexpr std::string_view ISLAND_LOW_POLY2 = "bonus/assets/new_island_low_poly4.gltf";
    constexpr std::string_view ISLAND_PLATFORM = "bonus/assets/plateform.obj";
    constexpr std::string_view ISLAND_TEXTURE = "bonus/assets/plateform1.png";

    constexpr std::string_view FOOD_MODEL = "bonus/assets/food.glb";
    constexpr std::string_view FOOD_TEXTURE = "bonus/assets/texture_food.png";
    constexpr std::string_view LINEMATE_MODEL = "bonus/assets/linemate.obj";
    constexpr std::string_view LINEMATE_TEXTURE = "bonus/assets/texture_linemate.png";
    constexpr std::string_view DERAUMERE_MODEL = "bonus/assets/deraumere.obj";
    constexpr std::string_view DERAUMERE_TEXTURE = "bonus/assets/texture_deraumere.png";
    constexpr std::string_view SIBUR_MODEL = "bonus/assets/sibur.obj";
    constexpr std::string_view SIBUR_TEXTURE = "bonus/assets/texture_sibur.png";
    constexpr std::string_view MENDIANE_MODEL = "bonus/assets/mendiane.obj";
    constexpr std::string_view MENDIANE_TEXTURE = "bonus/assets/texture_mendiane.png";
    constexpr std::string_view PHIRAS_MODEL = "bonus/assets/phiras.obj";
    constexpr std::string_view PHIRAS_TEXTURE = "bonus/assets/texture_phiras.png";
    constexpr std::string_view THYSTAME_MODEL = "bonus/assets/thystame.obj";
    constexpr std::string_view THYSTAME_TEXTURE = "bonus/assets/texture_thystame.png";

    constexpr std::string_view SPACESHIP_MODEL = "bonus/assets/spaceship.gltf";

    constexpr std::string_view EVOLUTION_TEXTURE = "bonus/assets/evolution.png";

    constexpr double sizeFontTextMenu = 0.05;
    constexpr std::string_view MENU_MARS_MODEL = "menu_scene.glb";
    constexpr std::string_view SPACE_TEXTURE = "bonus/assets/texture_space.png";
    constexpr std::string_view ZAPPY_LOGO = "bonus/assets/zappy_logo.png";

    constexpr std::string_view SOUND_GAME = "./bonus/song/kids.wav";
    constexpr std::string_view SOUND_ENDGAME = "./bonus/song/zappy_end_song.wav";
}

#endif /* !GAMECONFIG_HPP_ */
