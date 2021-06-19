//
// Created by ravens on 22/05/2021.
//

#ifndef INDIE_OPTIONSCENE_HPP
#define INDIE_OPTIONSCENE_HPP

#include "AScene.hpp"
#include "SceneManager.hpp"

namespace Indie::Scenes {
    class OptionScene : public Scenes::AScene {
    public:
        OptionScene(std::shared_ptr<Scenes::SceneManager> &);

        void display(const Graphical::Window &window) override;
        void event(Indie::Event event) override;
    };
}

#endif //INDIE_OPTIONSCENE_HPP
