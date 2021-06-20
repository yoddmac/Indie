/*
** EPITECH PROJECT, 2021
** indie
** File description:
** GameScene
*/

#include "GameScene.hpp"
#include <raylib.h>
#include <iostream>
#include <cmath>

Indie::Scenes::GameScene::GameScene(SceneManager &sceneManager) : Scenes::AScene("GameScene", sceneManager)
{
    this->_camera = {{0.0f, 60.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 15.0f, 0};
    this->_camera.projection = CAMERA_CUSTOM;
    this->_GenMap.CreateMap(10);
    this->_mapvect = this->_GenMap.getCreatedMap();
    this->_GenMap.AddMapToVector();

    for (unsigned int i = 0; i < this->_mapvect.size(); i++)
    {
        for (unsigned int j = 0; j < this->_mapvect[i].size(); j++)
            std::cout << this->_mapvect[i][j] << " ";
        std::cout << std::endl;
    }

    ::InitAudioDevice();

    sound = LoadSound("assets/Music/bombe.mp3");

    this->_bomb = LoadModel("assets/bomb/Bomb.obj");
    this->_textureBomb = LoadTexture("assets/bomb/TextureDiff2.png");
    SetMaterialTexture(&this->_bomb.materials[0], MAP_DIFFUSE, this->_textureBomb);

    this->_explosion = LoadModel("assets/bomb/Dramatic.obj");
    this->_textureExplosion = LoadTexture("assets/bomb/DramaticTexture.png");
    SetMaterialTexture(&this->_explosion.materials[0], MAP_DIFFUSE, this->_textureExplosion);


    ////    billylumberjack
    this->_billiModel = std::make_unique<Models::AModel>(
        "assets/models/lumberjack/lumberjack.iqm",
        "assets/models/lumberjack/texture.png",
        "assets/models/lumberjack/lumberjack_anim.iqm");

    std::vector<std::string> names = {
        "TPOSE",
        "IDLE"};

    this->_billiModel->setAnimationsNames(names);
    this->_billiModel->setCurrentAnimation("IDLE");
    this->_billiModel->setPlaySpeed(1);
    this->_billiModel->setRotationAngle(-90.0f); // Blender export fix.

    this->_billiModel->setScale({1.0f, 1.0f, 1.0f});
    this->_billiModel->setRotationAxis({1.0f, 0.0f, 0.0f});
    this->_billiModel->setPosition({1.0f, 0.0f, 0.0f});

    SetCameraMode(this->_camera, CAMERA_CUSTOM); // Set camera mode zoom/dezoom
}
void Indie::Scenes::GameScene::update(Event event, double deltaTime, const Indie::Graphical::Window &win)
{
    (void)event;
    this->_billiModel->update(deltaTime);
    this->_elapstedTime += deltaTime;
    if (this->_elapstedTime >= (60 / (0.08f * 60)))
    {
        this->_elapstedTime = 0;
        this->_timeBomb += 10;
        this->_timeExplosion += 10;
    }

    for(const auto& mode: this->_GenMap.getMapVector()) {
        mode->update(deltaTime);
    }

    // printf("this->_timeBomb = %d\n", this->_timeBomb);
    if (IsKeyDown(KEY_UP))
    {
        this->_billiModel->setPosition({this->_billiModel->getPosition().x, this->_billiModel->getPosition().y, (this->_billiModel->getPosition().z - 0.04f)});
        this->_billiModel->setRotationAxis({0.0f, 40.0f, 40.0f});
        this->_billiModel->setRotationAngle(900.0f); // Blender export fix.
    }
    if (IsKeyDown(KEY_DOWN))
    {
        this->_billiModel->setPosition({this->_billiModel->getPosition().x, this->_billiModel->getPosition().y, (this->_billiModel->getPosition().z + 0.04f)});
        this->_billiModel->setRotationAxis({1.0f, 0.0f, 0.0f});
        this->_billiModel->setRotationAngle(-90.0f); // Blender export fix.
    }
    if (IsKeyDown(KEY_LEFT))
    {
        this->_billiModel->setPosition({(this->_billiModel->getPosition().x - 0.04f), this->_billiModel->getPosition().y, this->_billiModel->getPosition().z});
        this->_billiModel->setRotationAxis({50.0f, 40.0f, 50.0f});
        this->_billiModel->setRotationAngle(-90.0f); // Blender export fix.
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        this->_billiModel->setPosition({(this->_billiModel->getPosition().x + 0.04f), this->_billiModel->getPosition().y, this->_billiModel->getPosition().z});
        this->_billiModel->setRotationAxis({-80.0f, 40.0f, 50.0f});
        this->_billiModel->setRotationAngle(-260.0f); // Blender export fix.
    }
    if (IsKeyDown(KEY_SPACE))
    {
        this->_dropBomb = true;
        this->_playerPose.x = this->_billiModel->getPosition().x;
        this->_playerPose.z = this->_billiModel->getPosition().z;

    }
    if (this->_timeBomb > 200 && this->_dropBomb == true)
    {
        this->_clear = true;
        this->_dropBomb = false;
        this->_timeBomb = 0;
        PlaySound(sound);
    }
    if(this->_timeExplosion > 250) {
        this->_clear = false;
        this->_timeExplosion = 0;
    }
}
void Indie::Scenes::GameScene::display(const Graphical::Window &win)
{
    (void)win;
    ::UpdateCamera(&this->_camera);
    ::BeginMode3D(this->_camera); // start camera 3D
    this->_billiModel->display();
    ::DrawBoundingBox(this->_billiModel->getBoundingBox(), RED);
    for(const auto& mode: this->_GenMap.getMapVector()) {
        mode->display();
        ::DrawBoundingBox(mode->getBoundingBox(), BLUE);
    }

    //::DrawModel(this->_model, this->_mapPosition, 1.0f, WHITE); // draw le model (ETIQUETTE)
    if (this->_dropBomb) {
        ::DrawModelEx(this->_bomb, {this->_playerPose.x, this->_PositionBilly.y, this->_playerPose.z}, Vector3{1.0f, 0.0f, 0.0f}, 0.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
        ::DrawModelEx(this->_bomb, {this->_playerPose.x, this->_PositionBilly.y, this->_playerPose.z + 1.0f}, Vector3{1.0f, 0.0f, 0.0f}, 0.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
        ::DrawModelEx(this->_bomb, {this->_playerPose.x, this->_PositionBilly.y, this->_playerPose.z - 1.0f}, Vector3{1.0f, 0.0f, 0.0f}, 0.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
        ::DrawModelEx(this->_bomb, {this->_playerPose.x + 1.0f, this->_PositionBilly.y, this->_playerPose.z}, Vector3{1.0f, 0.0f, 0.0f}, 0.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
        ::DrawModelEx(this->_bomb, {this->_playerPose.x - 1.0f, this->_PositionBilly.y, this->_playerPose.z}, Vector3{1.0f, 0.0f, 0.0f}, 0.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
    }
        if (this->_clear == true) {
            ::DrawModelEx(this->_explosion,
                          {this->_playerPose.x, this->_PositionBilly.y - 0.5f, this->_playerPose.z},
                          Vector3 {1.0f, 0.0f, 0.0f}, 0.0f, Vector3 {1.0f, 1.0f, 1.0f}, WHITE);
            ::DrawModelEx(this->_explosion,
                          {this->_playerPose.x, this->_PositionBilly.y - 0.5f, this->_playerPose.z + 1.0f},
                          Vector3 {1.0f, 0.0f, 0.0f}, 0.0f, Vector3 {1.0f, 1.0f, 1.0f}, WHITE);
            ::DrawModelEx(this->_explosion,
                          {this->_playerPose.x, this->_PositionBilly.y - 0.5f, this->_playerPose.z - 1.0f},
                          Vector3 {1.0f, 0.0f, 0.0f}, 0.0f, Vector3 {1.0f, 1.0f, 1.0f}, WHITE);
            ::DrawModelEx(this->_explosion,
                          {this->_playerPose.x + 1.0f, this->_PositionBilly.y - 0.5f, this->_playerPose.z},
                          Vector3 {1.0f, 0.0f, 0.0f}, 0.0f, Vector3 {1.0f, 1.0f, 1.0f}, WHITE);
            ::DrawModelEx(this->_explosion,
                          {this->_playerPose.x - 1.0f, this->_PositionBilly.y - 0.5f, this->_playerPose.z},
                          Vector3 {1.0f, 0.0f, 0.0f}, 0.0f, Vector3 {1.0f, 1.0f, 1.0f}, WHITE);
        }
    ::DrawGrid(20, 1.0f);
    ::EndMode3D();
}

Indie::Scenes::GameScene::~GameScene()
{
    if (this->_dropBomb)
    {
        ::UnloadTexture(this->_textureBomb);
        ::UnloadModel(this->_bomb);
    }

    if (this->_clear == false) {
        ::UnloadTexture(this->_textureExplosion);
        ::UnloadModel(this->_explosion);
        ::StopSound(sound);
    }
    ::UnloadModel(this->_model);
    ::UnloadTexture(this->_texture);
}
