//
// Created by razvan on 4/9/25.
//

#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include <string>
#include "DogBreeds.h"


class Dog : public Animal {
private:
    int obedience;
    int agility;
    DogBreed breed;
public:
    Dog(const std::string &name, int age, const std::string &advantage,
       DogBreed breed, int basePerformance, int price, int obedience,
       int agility, int energy);

    // Copy constructor
    Dog(const Dog& other);

    // Assignment operator
    Dog& operator=(const Dog& other);

    virtual ~Dog();

    [[nodiscard]] double calculatePerformance() const override;
    void train() override;
    void rest() override;

    void applyAdvantage();
    void applyBreedUpgrades();
    void ageDowngrade();
    int getPrice() const override;
};

#endif //DOG_H
