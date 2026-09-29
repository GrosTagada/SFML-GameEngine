cmake_minimum_required(VERSION 3.28)

cmake_policy(SET CMP0091 NEW)

project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

get_target_property(SFML_INCLUDE_DIRS SFML::Graphics INTERFACE_INCLUDE_DIRECTORIES)

message(STATUS "SFML INCLUDE DIRS = ${SFML_INCLUDE_DIRS}")

add_executable(CMakeSFMLProject
    src/main.cpp
    src/GameWindow.cpp
    src/GameWindow.h
)

target_compile_features(CMakeSFMLProject PRIVATE cxx_std_17)

target_include_directories(CMakeSFMLProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(CMakeSFMLProject PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
message(STATUS "SFML INCLUDE DIRS: ${SFML_INCLUDE_DIRS}")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CMakeSFMLProject)