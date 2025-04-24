#include "Rider.h"
#include <iostream>

// Constructor
Rider::Rider(const std::string &name, const std::string &description, int wins, int losses,
             const Horse& initialHorse, const Dog& initialDog) :
    name(name),
    description(description),
    wins(wins),
    losses(losses) {
    horse = new Horse(initialHorse);
    dog = new Dog(initialDog);
}

Rider::Rider(const Rider& other) :
    name(other.name),
    description(other.description),
    wins(other.wins),
    losses(other.losses) {
    horse = new Horse(*(other.horse));
    dog = new Dog(*(other.dog));
}

// Assignment operator
Rider& Rider::operator=(const Rider& other) {

    if (this != &other) {

        name = other.name;
        description = other.description;
        wins = other.wins;
        losses = other.losses;

        delete horse;
        delete dog;
        

        horse = new Horse(*(other.horse));
        dog = new Dog(*(other.dog));
    }
    return *this;
}

// Destructor
Rider::~Rider() {
    delete horse;
    delete dog;
}

// Increment wins
Rider& Rider::operator++(int) {
    wins++;
    return *this;
}


Rider& Rider::operator--(int) {
    losses++;
    return *this;
}

void Rider::showInfo() const {
    std::cout << "Rider: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Record: " << wins << " wins, " << losses << " losses" << std::endl;
}


void Rider::setHorse(const Horse& newHorse) {
    delete horse;
    horse = new Horse(newHorse);
}

void Rider::setDog(const Dog& newDog) {
    delete dog;
    dog = new Dog(newDog);
}