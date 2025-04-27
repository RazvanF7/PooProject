//
// Created by razvan on 4/9/25.
//
#include <iostream>
#include "Horse.h"
#include <stdexcept>
Horse::Horse(const std::string &name, int age, const std::string &advantage,
             HorseBreed breed, int basePerformance, int price, int energy,
             int speed, int endurance)
    : Animal(name, age, advantage, basePerformance, price, energy),
      endurance(endurance),
      speed(speed),
      breed(breed)
{
    applyBreedUpgrades();  // Apply breed modifiers on creation
}

// Copy constructor
Horse::Horse(const Horse& other) :

    Animal(other),
    endurance(other.endurance),
    speed(other.speed),
    breed(other.breed)
{

}

// Assignment operator
Horse& Horse::operator=(const Horse& other) {

    if (this != &other) {

        Animal::operator=(other);


        endurance = other.endurance;
        speed = other.speed;
    }


    return *this;
}

 Horse::~Horse() {

}

double Horse::calculatePerformance() const {

    return basePerformance + speed*0.6 + endurance*0.4;
}
void Horse::train() {
    if (energy < 20) {
        throw std::runtime_error("Horse's energy is too low to train!");
    }
    energy -= 20; // Training decreases energy
    std::cout << "Horse trained successfully. Remaining energy: " << energy << std::endl;
    speed+=10;
    endurance+=20;
}

void Horse::rest() {
    if (energy > 100) {
        throw std::runtime_error("Horse's energy is too high!");
    }
    energy +=50;
    if (energy > 100) {energy = 100;}
    std::cout<< "Horse rested successfully. Remaining energy: " << energy << std::endl;

}

void Horse::applyAdvantage() {
    if (advantage=="Power")
        speed+=20;
    if (advantage=="Endurance")
        endurance+=20;
    if (advantage=="Strategy") {
        speed+=10;
        endurance+=10;
    }
    if (advantage=="Willpower") {
        speed+=15;
        endurance+=5;
    }
}

void Horse::applyBreedUpgrades() {
    switch (breed) {
        case HorseBreed::Arabian:
            speed += 40;
        endurance -= 20;
        break;
        case HorseBreed::American:
            speed -= 20;
        endurance += 40;
        break;
        case HorseBreed::Mustang:
            endurance += 30;
        speed -= 10;
        break;
        case HorseBreed::Spanish:
            speed += 30;
        endurance -= 20;
        break;
        case HorseBreed::Icelandic:
            endurance += 40;
            speed -= 5;
    }
}

void Horse::ageDowngrade() {
    if (age>8) {
        endurance-=40;
        speed-=20;
    }
    if (age>12) {
        endurance-=60;
        speed-=40;
    }
    if (age>16) {
        endurance-=80;
        speed-=60;
    }
}

int Horse::getPrice() const {
    return price;
}



