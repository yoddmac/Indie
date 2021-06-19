/*
** EPITECH PROJECT, 2020
** SceneManager.cpp
** File description:
** SceneManager function
*/

#include "MenuScene.hpp"
#include "OptionScene.hpp"
#include "SceneManager.hpp"
#include "SceneManagerError.hpp"

#include <iostream>

void Indie::Scenes::SceneManager::changeScene(
    const std::string &name,
    std::shared_ptr<SceneManager> sceneManager
)
{
    for (const auto &scene : this->_scenes) {
        if (scene == name) {
            this->_currScene = std::shared_ptr<IScene>(SceneManager::createScene(name, sceneManager));

            return;
        }
    }

    throw Errors::SceneManagerError("Scene doesn't exist", __func__);
}

void Indie::Scenes::SceneManager::addScene(const std::string &name)
{
    this->_scenes.push_back(name);
}

std::shared_ptr<Indie::Scenes::IScene> Indie::Scenes::SceneManager::getCurrentScene() const
{
    return this->_currScene;
}

Indie::Scenes::IScene *Indie::Scenes::SceneManager::createScene(
    const std::string &name,
    std::shared_ptr<SceneManager> sceneManager
)
{
    if (name == "OptionScene") return new OptionScene(sceneManager);
    if (name == "MenuScene") return new MenuScene(sceneManager);

    throw Errors::SceneManagerError("Scene is not implemented.", __func__);
}
