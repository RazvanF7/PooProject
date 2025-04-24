//
// Created by razvan on 4/9/25.
//

#ifndef RIDER_H
#define RIDER_H
#include <string>

#include "Dog.h"
#include "Horse.h"

class Rider {
private:
    std::string name;
    std::string description;
    int wins;
    int losses;
    Horse* horse;    // Horse owned by the rider
    Dog* dog;        // Dog owned by the rider

public:
    // Constructor
    Rider(const std::string &name, const std::string &description, int wins, int losses,
          const Horse& initialHorse, const Dog& initialDog);

    // Copy constructor
    Rider(const Rider& other);

    // Assignment operator
    Rider& operator=(const Rider& other);

    // Destructor
    ~Rider();

    // Increment/decrement operators for wins/losses
    Rider& operator++(int);   // Increment wins
    Rider& operator--(int);   // Increment losses

    // Show rider information
    void showInfo() const;

    // Getters for horse and dog
    Horse* getHorse() const { return horse; }
    Dog* getDog() const { return dog; }

    // Setters for horse and dog
    void setHorse(const Horse& newHorse);
    void setDog(const Dog& newDog);
};

#endif //RIDER_H
