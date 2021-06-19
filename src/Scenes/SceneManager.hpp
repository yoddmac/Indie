/*
** EPITECH PROJECT, 2020
** SceneManager.hpp
** File description:
** SceneManager header file
*/

#ifndef SceneManager_H_
#define SceneManager_H_

#include "IScene.hpp"

#include <vector>
#include <memory>

namespace Indie::Scenes {
    class SceneManager {
        public:
            SceneManager() = default;

            void addScene(const std::string &name);
            void changeScene(
                const std::string &name,
                std::shared_ptr<SceneManager> sceneManager
            );

            std::shared_ptr<IScene> getCurrentScene() const;

            static IScene *createScene(
                const std::string &name,
                std::shared_ptr<SceneManager> sceneManager
            );
        private:
            std::vector<std::string> _scenes;

            std::shared_ptr<IScene> _currScene;
    };
}

#endif
