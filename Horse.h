// Horse.h

#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"
#include <string>

class Horse : public Animal {
private:
    int endurance;
    int speed;

public:
    Horse(const std::string &name, int age, const std::string &advantage,
          const std::string &breed, int basePerformance, int price,int energy, int speed, int endurance);

    // Copy constructor
    Horse(const Horse& other);

    // Assignment operator
    Horse& operator=(const Horse& other);

    virtual ~Horse();


   [[nodiscard]] double calculatePerformance() const override;
    void train() override;

    void rest()override;

    void applyAdvantage();

    void applyBreedUpgrades();

    void ageDowngrade();

    int getPrice()const override;
};

#endif // HORSE_H

