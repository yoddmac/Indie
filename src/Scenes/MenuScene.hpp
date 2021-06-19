//
// Created by ravens on 22/05/2021.
//

#ifndef INDIE_MENUSCENE_HPP
#define INDIE_MENUSCENE_HPP

#include "AScene.hpp"

namespace Indie::Scenes {
    class MenuScene : public Scenes::AScene {
        public:
            MenuScene(std::shared_ptr<Scenes::SceneManager> &sceneManager);

            void event(Indie::Event event) final;
            void display(const Graphical::Window &window) final;
    };
}
#endif //INDIE_MENUSCENE_HPP
