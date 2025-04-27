//
// Created by razvan on 4/9/25.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>


class Animal {
    protected:
        std::string name;
        int age;
        std::string advantage;
        int basePerformance;
        int price;
        int energy;


    public:

            Animal(const std::string &name, int age, const std::string &advantage, int basePerformance, int price,int energy);

            // Copy constructor
            Animal(const Animal& other);

            // Assignment operator
            Animal& operator=(const Animal& other);
            [[nodiscard]] virtual double calculatePerformance() const = 0;

            friend std::ostream &operator<<(std::ostream &os, const Animal &animal);

            virtual ~Animal();

            std::string getName()const;

            int getAge()const;

            Animal& operator++(int);
            virtual void train();
            virtual void rest();

            virtual int getPrice()const;
};



#endif //ANIMAL_H
