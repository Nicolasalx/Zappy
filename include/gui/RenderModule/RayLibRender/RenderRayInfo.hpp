/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** player
*/

#ifndef RENDERRAYINFO_H_
    #define RENDERRAYINFO_H_
    #include <raylib.h>

namespace Gui {

    struct RayInfoData {
        int type = 0;
        int id = 0;
        int x = 0;
        int y = 0;
    };

    class RayInfo {
        public:
            RayInfo() = default;
            ~RayInfo() = default;
            
        private:
            Ray ray;
            BoundingBox box;
            RayCollision collision;
            int type = 0;
            int id = 0;
            int x = 0;
            int y = 0;
    };
}

#endif /* !RENDERRAYINFO_H_ */