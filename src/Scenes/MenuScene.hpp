/*
** EPITECH PROJECT, 2020
** MenuScene.cpp
** File description:
** MenuScene function
*/

#ifndef INDIE_MENUSCENE_HPP
#define INDIE_MENUSCENE_HPP

#include "AScene.hpp"

namespace Indie::Scenes {
    class MenuScene : public Scenes::AScene {
        public:
            MenuScene(SceneManager &sceneManager);

            void display(const Graphical::Window &window) final;
            void update(Indie::Event event, double deltaTime) final;
    };
}
#endif
