/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** Player
*/

#ifndef ARAYLIBMODEL_H_
    #define ARAYLIBMODEL_H_

    #include "GameData.hpp"
    #include <raylib.h>
    #include <iostream>
    #include <vector>

namespace Gui
{
    /**
     * @brief Struct containing the model index, the position, the rotation angle, the rotation, the scale and his color
    */
    struct ModelInfo {
        int index;
        Vector3 pos;
        Vector3 rotation_angle;
        float rotation;
        Vector3 scale;
        Color color;
    };

    class ARayLibModel {
        public:
            ARayLibModel() = default;
            ~ARayLibModel();
            /**
             * @brief Add a model to the _models vector
             * 
             * @param std::string model: path to the model
             * @param std::string texture: path to the texture
            */
            void addModel(std::string model, std::string texture);
            void addModel(std::string model);

            /**
             * @brief Draw a model with the given ModelInfo struct
             * 
             * @param int index: index of the model in the _models vector
             * @param Vector3 pos: position of the model
             * @param Vector3 rotation_angle: rotation angle of the model
             * @param float rotation: rotation of the model
             * @param Vector3 scale: scale of the model
             * @param Color color: color of the model
            */
            void drawModel(const ModelInfo &modelInfo);
            
            /**
             * @brief Render the models. This function should be overriden in the child class
            */
            virtual void render(const GameData &gameData) = 0;

        protected:
            std::vector<Model> _models;
            std::vector<Texture2D> _textures;
    };
}

#endif /* !ARAYLIBMODEL_H_ */