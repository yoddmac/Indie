//
// Created by ravens on 22/05/2021.
//

#include "MenuScene.hpp"
#include "SceneManager.hpp"
#include <raylib.h>

Indie::Scenes::MenuScene::MenuScene(std::shared_ptr<Scenes::SceneManager> &sceneManager) : AScene("MenuScene", sceneManager)
{

}

void Indie::Scenes::MenuScene::event(Indie::Event e)
{
    if (e.keyEvent == KeyEvent::ENTER) {
        this->_sceneManager->changeScene("OptionScene", this->_sceneManager);
    }
}

void Indie::Scenes::MenuScene::display(const Indie::Graphical::Window &win)
{
    ::ClearBackground(::GRAY);
    auto textPos = win.getPos(50, 50);
    ::DrawText("MenueScene", textPos.x, textPos.y, 30, ::BLACK);
}
