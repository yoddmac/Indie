/*
** EPITECH PROJECT, 2020
** OptionScene.cpp
** File description:
** OptionScene file
*/

#include "OptionScene.hpp"
#include <raylib.h>

Indie::Scenes::OptionScene::OptionScene(std::shared_ptr<Scenes::SceneManager> &sceneManager) : AScene("OptionScene", sceneManager)
{

}

void Indie::Scenes::OptionScene::display(const Indie::Graphical::Window &win)
{
    ::ClearBackground(::GRAY);
    auto textPos = win.getPos(50, 50);
    ::DrawText("OptionScene", textPos.x, textPos.y, 30, ::BLACK);
}

void Indie::Scenes::OptionScene::event(Indie::Event e)
{
    if (e.keyEvent == KeyEvent::ENTER) {
        std::cout << "UUUUP\n";
    }
}
