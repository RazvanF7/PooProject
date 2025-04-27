#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"
#include "HorseBreeds.h"

class Horse : public Animal {
private:
    int endurance;
    int speed;
    HorseBreed breed;

public:
    Horse(const std::string &name, int age, const std::string &advantage,
          HorseBreed breed, int basePerformance, int price, int energy, 
          int speed, int endurance);

    // Copy constructor
    Horse(const Horse& other);

    // Assignment operator
    Horse& operator=(const Horse& other);

    ~Horse() override;

    [[nodiscard]] double calculatePerformance() const override;
    void train() override;
    void rest() override;

    void applyAdvantage();
    void applyBreedUpgrades();
    void ageDowngrade();
    int getPrice() const override;
};

#endif