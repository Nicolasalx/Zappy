/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** object
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include "raylibInfo.hpp"
    #include <vector>

namespace Gui
{
    class Object {
        public:
            Object(std::vector<Model> &modelList);
            ~Object() = default;

        private:

    };
}

#endif /* !OBJECT_H_ */
