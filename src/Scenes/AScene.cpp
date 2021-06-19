/*
** EPITECH PROJECT, 2020
** AScene.cpp
** File description:
** AScene function
*/

#include "AScene.hpp"
#include <iostream>
#include <raylib.h>

Indie::Scenes::AScene::AScene(const std::string &name, std::shared_ptr<Scenes::SceneManager> sceneManager)
{
    this->_name = name;
    this->_sceneManager = sceneManager;
}

std::string Indie::Scenes::AScene::getName() const
{
    return this->_name;
}

void Indie::Scenes::AScene::display(const Indie::Graphical::Window &win)
{
    ::ClearBackground(::GRAY);
    auto textPos = win.getPos(50, 50);
    ::DrawText("Default Scene", textPos.x, textPos.y, 30, ::BLACK);
}

void Indie::Scenes::AScene::event(Indie::Event e)
{
    (void)e;
}
