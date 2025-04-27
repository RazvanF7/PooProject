//
// Created by razvan on 4/9/25.
//

#include "Dog.h"
#include <iostream>
Dog::Dog(const std::string &name, int age, const std::string &advantage, DogBreed breed,
             const int basePerformance, int price, int obedience, int agility,int energy)
    : Animal(name, age, advantage, basePerformance,price,energy),
      obedience(obedience),
      agility(agility),
      breed(breed)
{
    applyBreedUpgrades();
}

// Copy constructor
Dog::Dog(const Dog& other) :
    Animal(other),
    obedience(other.obedience),
    agility(other.agility),
    breed(other.breed)
{
}

// Assignment operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        obedience = other.obedience;
        agility = other.agility;
        breed = other.breed;
    }

    // Return a reference to this object
    return *this;
}

Dog::~Dog() {
}

double Dog::calculatePerformance() const {

    return basePerformance + agility * 0.2 + obedience*0.3- 5*age;
}
void Dog::train() {
    if (energy < 20) {
        throw std::runtime_error("Dog's energy is too low to train!");
    }
    energy -= 20; // Training decreases energy
    std::cout << "Dog trained successfully. Remaining energy: " << energy << std::endl;
    agility = agility + 10;
    obedience = obedience + 20;
}

void Dog::rest() {
    if (energy > 100) {
        throw std::runtime_error("Dog's energy is too high!");
    }
    energy +=50;
    if (energy > 100) {
        energy = 100;
    }
    std::cout<< "Dog rested successfully. Remaining energy: " << energy << std::endl;

}

void Dog::applyAdvantage() {
    if (advantage=="Agility")
        agility+=20;
    if (advantage=="Intelligence")
        obedience+=20;
    if (advantage=="Wisdom") {
        agility+=10;
        obedience+=10;
    }
    if (advantage=="Adaptability") {
        agility+=15;
        obedience+=5;
    }
}

void Dog::applyBreedUpgrades() {
    switch (breed) {
        case DogBreed::BorderCollie:
            agility += 40;
        obedience -= 20;
        break;
        case DogBreed::Greyhound:
            agility -= 20;
        obedience += 40;
        break;
        case DogBreed::Dalmatian:
            obedience += 30;
        agility -= 10;
        break;
        case DogBreed::GermanShepherd:
            agility += 30;
        obedience -= 20;
        break;
        case DogBreed::Husky:
            obedience -= 30;
            agility += 25;
        break;
    }
}

void Dog::ageDowngrade() {
    if (age>8) {
        obedience-=20;
        agility-=40;
    }
    if (age>12) {
        obedience-=40;
        agility-=80;
    }
    if (age>16) {
        obedience-=50;
        agility-=100;
    }
}
int Dog::getPrice() const {
    return price;
}



