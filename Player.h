#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Horse.h"
#include "Dog.h"


class Player {
    std::string name;
    int money;
    int wins;
    int losses;
    std::vector<Horse> horses;
    std::vector<Dog> dogs;

public:
    Player(const std::string &name);

    Player(const Player &other)
        : name(other.name), money(other.money), wins(other.wins), losses(other.losses),
          horses(other.horses), dogs(other.dogs) {}

    // Assignment operator
    Player& operator=(const Player &other);

    // +Money
    Player& operator+=(int amount);

    // -Money
    Player& operator-=(int amount);

    [[nodiscard]] int getMoney() const;

    // Wins++
    Player& operator++(int);

    // Losses++
    Player& operator--(int);

    friend std::istream &operator>>(std::istream &is, Player &player);
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    void sortHorsesByPerformance();

    void sortDogsByPerformance();

    void addDog(const Dog &dog);
    bool removeDogAtIndex(size_t index);


    void addHorse(const Horse &horse);
    bool removeHorseAtIndex(size_t index);


    [[nodiscard]] const std::vector<Dog>&getDogs() const;

    [[nodiscard]] const std::vector<Horse>&getHorses() const;

};

#endif // PLAYER_H
