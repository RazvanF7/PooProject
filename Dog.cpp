//
// Created by razvan on 4/9/25.
//

#include "Dog.h"
#include <iostream>
Dog::Dog(const std::string &name, int age, const std::string &advantage,
             const std::string &breed, const int basePerformance, int price, int obedience, int agility,int energy)
    : Animal(name, age, advantage, breed, basePerformance,price,energy),
      obedience(obedience),
      agility(agility)
{}

// Copy constructor
Dog::Dog(const Dog& other) :
    // Call the base class (Animal) copy constructor first
    Animal(other),
    // Copy the Dog-specific member variables
    obedience(other.obedience),
    agility(other.agility)
{
}

// Assignment operator
Dog& Dog::operator=(const Dog& other) {
    // Check for self-assignment
    if (this != &other) {
        // Call base class assignment operator
        Animal::operator=(other);

        // Copy Dog-specific member variables
        obedience = other.obedience;
        agility = other.agility;
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
    if (breed=="Border Collie") {
        agility+=40;
        obedience-=20;
    }
    if (breed=="Greyhound") {
        agility-=20;
        obedience+=40;
    }

    if (breed=="Dalmatian") {
        obedience+=30;
        agility-=10;
    }
    if (breed=="German Shepherd") {
        agility+=30;
        obedience-=20;
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



