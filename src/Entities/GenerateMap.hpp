/*
** EPITECH PROJECT, 2020
** AModel.hpp
** File description: Function to generation map
** GenerationMap cpp file
*/

#ifndef INDIE_GENERATEMAP_HPP
#define INDIE_GENERATEMAP_HPP
#include "AModel.hpp"
#include <vector>
#include <iostream>
#include <memory>

namespace Indie::Entities {
    class GenerateMap {
    public :
        GenerateMap();
        void CreateMap(uint, uint = 3);
        ~GenerateMap();
        void AddMapToVector();
        std::vector<std::vector<int>> getCreatedMap();
        std::vector<std::unique_ptr<Models::IModel>> &getMapVector();
    private :
        std::vector<std::vector<int>> _mapvect;
        std::vector<std::unique_ptr<Models::IModel>> _modelVect;
        std::vector<std::unique_ptr<Models::IModel>> _modelFloor;

        uint _width;
        uint _height;
    };

}
#endif //INDIE_GENERATEMAP_HPP
