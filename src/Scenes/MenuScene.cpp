/*
** EPITECH PROJECT, 2020
** MenuScene.cpp
** File description:
** MenuScene function
*/

#include "MenuScene.hpp"
#include "SceneManager.hpp"

#include <raylib.h>

Indie::Scenes::MenuScene::MenuScene(SceneManager &sceneManager) : AScene("MenuScene", sceneManager)
{

}

void Indie::Scenes::MenuScene::update(Indie::Event e, double deltaTime)
{
    AScene::update(e, deltaTime);
    if (e.keyEvent == KeyEvent::ENTER) {
        this->_sceneManager.changeScene("GameScene");
    }
}

void Indie::Scenes::MenuScene::display(const Indie::Graphical::Window &win)
{
    ::ClearBackground(::GRAY);
    auto textPos = win.getPos(50, 50);
    ::DrawText("MenuScene", textPos.x, textPos.y, 30, ::BLACK);
}
