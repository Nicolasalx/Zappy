/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** raylibInfo
*/

#ifndef RAYLIBINFO_H_
    #define RAYLIBINFO_H_

    #include <raylib.h>
    #include <rlgl.h>
    #include <raymath.h>

namespace Gui
{
    struct ray_info_t {
        Ray ray;
        BoundingBox box;
        RayCollision collision;
        int type = 0;
        int id = 0;
        int x = 0;
        int y = 0;
    };

    class RAYLIBINFO {
        public:

        private:
    };
}

#endif /* !RAYLIBINFO_H_ */
