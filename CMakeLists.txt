cmake_minimum_required(VERSION 3.10)

project(indie CXX)

set(BIN_NAME bomberman)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/)

FIND_PACKAGE(raylib REQUIRED)

add_executable(${BIN_NAME}
    ${CMAKE_SOURCE_DIR}/src/main.cpp

    ${CMAKE_SOURCE_DIR}/src/Errors/IndieError.cpp
    ${CMAKE_SOURCE_DIR}/src/Errors/SceneManagerError.cpp

    ${CMAKE_SOURCE_DIR}/src/Graphical/Window.cpp

    ${CMAKE_SOURCE_DIR}/src/Scenes/AScene.cpp
    ${CMAKE_SOURCE_DIR}/src/Scenes/MenuScene.cpp
    ${CMAKE_SOURCE_DIR}/src/Scenes/OptionScene.cpp
    ${CMAKE_SOURCE_DIR}/src/Scenes/SceneManager.cpp
)

target_include_directories(${BIN_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src/
    ${CMAKE_SOURCE_DIR}/src/Errors/
    ${CMAKE_SOURCE_DIR}/src/Scenes/
    ${CMAKE_SOURCE_DIR}/src/Graphical/
)

target_compile_options(${BIN_NAME} PRIVATE
    -W
    -Wall
    -Wextra
    -Werror
    -pedantic
    -std=c++17
    -g
)

target_link_libraries(${BIN_NAME} PRIVATE
    raylib
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${BIN_NAME} PRIVATE
        -DINDIE_DEBUG=true
    )
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
