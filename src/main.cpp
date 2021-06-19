/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main function
*/

#include "Indie.hpp"
#include "AScene.hpp"
#include "Window.hpp"
#include "SceneManager.hpp"
#include "MenuScene.hpp"
#include "OptionScene.hpp"

#include <cstring>

static void parseArguments(int ac, char *av[])
{
    /*for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "--debug") == 0) {
            #undef INDIE_DEBUG
            #define INDIE_DEBUG true
        }
    }*/
    (void)ac;
    (void)av;
}

int main(int ac, char *av[])
{
    auto sceneManager = std::make_shared<Indie::Scenes::SceneManager>();
    Indie::Graphical::Window window = Indie::Graphical::Window(1920, 1280);

    parseArguments(ac, av);
    sceneManager->addScene("MenuScene");
    sceneManager->addScene("OptionScene");
    sceneManager->changeScene("MenuScene", sceneManager);

    while (window.isOpened()) {
        window.setScene(sceneManager->getCurrentScene());
        sceneManager->getCurrentScene()->event(window.getEvent());
        window.display();
    }

    return 0;
}
