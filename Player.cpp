//
// Created by razvan on 4/9/25.
//
#include<iostream>
#include "Player.h"
#include "Dog.h"
#include "Horse.h"
#include<algorithm>


Player::Player(const std::string &name)
    : name(name), money(1000), wins(0), losses(0), horses(), dogs() {}


std::istream &operator>>(std::istream &is, Player &player) {
    is >> player.name;
    return is;
}
Player& Player::operator++(int) {
    wins++;
    return *this;
}
Player& Player::operator+=(int amount) {
    money += amount;
    return *this;
}


// -Money
Player& Player::operator-=(int amount) {
    money -= amount;
    return *this;
}

Player& Player:: operator=(const Player &other) {
    if (this != &other) {
        name = other.name;
        money = other.money;
        wins = other.wins;
        losses = other.losses;
    }
    return *this;
}


int Player::getMoney() const { return money; }
// Update player's betting record: increment loss count.
Player& Player::operator--(int) {
    losses++;
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os  << "Player: " << player.name
        << "\nMoney: " << player.money
        << "\nWins: " << player.wins
        << "\nLosses: " << player.losses << "\n";
    return os;
}

void Player::sortHorsesByPerformance() {
    std::sort(horses.begin(), horses.end(),
              [](const Horse &a, const Horse &b) {
                  return a.calculatePerformance() > b.calculatePerformance();
              });
}


void Player::sortDogsByPerformance() {
    std::sort(dogs.begin(), dogs.end(),
              [](const Dog &a, const Dog &b) {
                  return a.calculatePerformance() > b.calculatePerformance();
              });
}

void Player::addHorse(const Horse &horse) {
    horses.push_back(horse);
}

bool Player::removeHorseAtIndex(size_t index) {
    if (index < horses.size()) {
        horses.erase(horses.begin() + index);
        return true;
    }
    return false;
}

void Player::addDog(const Dog &dog) {
    dogs.push_back(dog);
}

bool Player::removeDogAtIndex(size_t index) {
    if (index < dogs.size()) {
        dogs.erase(dogs.begin() + index);
        return true;
    }
    return false;
}

const std::vector<Horse>& Player::getHorses() const {
    return horses;
}

// Getter: Retrieve a constant reference to the player's dogs.
const std::vector<Dog>& Player::getDogs() const {
    return dogs;
}