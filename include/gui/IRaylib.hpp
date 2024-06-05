/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** render
*/

#ifndef IRAYLIB_H_
    #define IRAYLIB_H_

    #include <iostream>
    #include <raylib.h>
    #include <vector>

namespace Gui
{
    struct ModelInfo {
        int index;
        Vector3 pos;
        Vector3 rotation_angle;
        float rotation;
        Vector3 scale;
        Color color;
    };

    class IRaylib {
        public:
            IRaylib() = default;
            ~IRaylib();
            void addModel(std::string model, std::string texture);
            void drawModel(const ModelInfo &modelInfo);

            virtual void render() = 0;
        protected:
            std::vector<Model> _models;
            std::vector<Texture2D> _textures;
    };
}

#endif /* !IRAYLIB_H_ */