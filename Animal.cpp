//
// Created by razvan on 4/9/25.
//

#include "Animal.h"
#include <iostream>
Animal::Animal(const std::string &name, int age, const std::string &advantage,int basePerformance, int price, int energy):
    name(name),
    age(age),
    advantage(advantage),
    basePerformance(basePerformance),
    price(price),
    energy(100)
{}

Animal::Animal(const Animal& other) :
    name(other.name),
    age(other.age),
    advantage(other.advantage),
    basePerformance(other.basePerformance),
    price(other.price),
    energy(other.energy)
{}

// Assignment operator
Animal& Animal::operator=(const Animal& other) {
    // Check for self-assignment
    if (this != &other) {
        name = other.name;
        age = other.age;
        advantage = other.advantage;
        basePerformance = other.basePerformance;
        price = other.price;
        energy = other.energy;
    }

    // Return reference to this object
    return *this;
}
//Destructor
Animal::~Animal() = default;

std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os  << "Animal name: " << animal.name
        << "\nAge: " << animal.age
        << "\nPerformance: " << animal.basePerformance << "\n"<<
            "\nSpecial Atribute: " << animal.advantage<<"\n"<<
             "Price: "<<animal.price<<"\n";
    return os;
}
    int Animal::getPrice()const {
    return price;
}


std::string Animal::getName() const {
    return name;
}
int Animal::getAge() const {
    return age;
}
Animal &Animal::operator++(int) {
    age++;
    return *this;
}

void Animal::train() {
    if (energy < 20) {
        throw std::runtime_error("Animals's energy is too low to train!");
    }
    energy -= 10; // Training decreases energy
    std::cout << "Animal trained successfully. Remaining energy: " << energy << std::endl;
}

void Animal::rest() {
    if (energy > 100) {
        throw std::runtime_error("Animal's energy is too high!");
    }
    energy = 100;
    std::cout<< "Animal rested successfully. Remaining energy: " << energy << std::endl;
}

