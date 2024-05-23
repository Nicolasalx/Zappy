/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** main
*/

/*
    1) Faire un lien avec le serveur

    - IA qui mange sur sa case
    - Se déplace à une prochaine case puis remange
*/

#include "zappy_ai.hpp"

int main(int argc, char const *argv[])
{
    try {
        Ai::Client client(argc, argv);
        client.createClient();
        client.launchClient();
    } catch (my::tracked_exception &e) {
        my::log::error(e.what());
        return 84;
    }
    return 0;
}
