/*
** EPITECH PROJECT, 2020
** AScene.hpp
** File description:
** AScene header file
*/

#ifndef AScene_H_
#define AScene_H_

#include "IScene.hpp"
#include "SceneManager.hpp"

#include <memory>
#include <vector>

namespace Indie::Graphical {
    struct keyboardManage;
}

namespace Indie::Scenes {
    class AScene : public IScene {
        public:
            AScene(const std::string &name, std::shared_ptr<Scenes::SceneManager> sceneManager);

            void event(Event event) override;
            void display(const Graphical::Window &window) override ;

            std::string getName() const final;
        protected:
            std::string _name;
            std::shared_ptr<Scenes::SceneManager> _sceneManager;
    };
}

#endif
