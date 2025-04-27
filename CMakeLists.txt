cmake_minimum_required(VERSION 3.30)
project(PooProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(PooProject main.cpp
        Animal.cpp
        Animal.h
        Horse.cpp
        Horse.h
        Player.cpp
        Player.h
        WeatherCondition.cpp
        WeatherCondition.h
        Dog.cpp
        Dog.h
        Job.cpp
        Job.h
        Rider.cpp
        Rider.h
        Shop.cpp
        Shop.h
        Game.cpp
        Game.h
        Competition.cpp
        Competition.h
        DogBreeds.h
        HorseBreeds.h)
