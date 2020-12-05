cmake_minimum_required(VERSION 3.5)

project(OOP-UNSA-A LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS -pthread) # Linux

file(GLOB files "*.h" "*.cpp") # files es nombre

add_executable(OOP-UNSA-A  main.cpp ${files} ) #linking
