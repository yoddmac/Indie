/*
** EPITECH PROJECT, 2020
** OptionScene.cpp
** File description:
** OptionScene function
*/

#ifndef INDIE_OPTIONSCENE_HPP
#define INDIE_OPTIONSCENE_HPP

#include "AScene.hpp"
#include "SceneManager.hpp"

namespace Indie::Scenes {
    class OptionScene : public Scenes::AScene {
    public:
        OptionScene(Scenes::SceneManager &sceneManager);

        void display(const Graphical::Window &window) override;
        void update(Indie::Event event, double deltaTime) override;
    };
}

#endif
