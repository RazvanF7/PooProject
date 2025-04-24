#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Dog.h"
#include "Horse.h"
#include "Player.h"

class Shop {
private:
    std::vector<Dog> dogsShop;
    std::vector<Horse> horsesShop;

public:
    Shop() = default;
    ~Shop() = default;

    // Add a Dog to the shop.
    void addDog(const Dog &dog);

    // Add a Horse to the shop.
    void addHorse(const Horse &horse);

    // Lista Dog
    const std::vector<Dog> &getDogs() const;

    // Lista Horse
    const std::vector<Horse> &getHorses() const;

    //  Transaction functions
    bool playerBuysDog(Player &player, size_t shopDogIndex);

    bool playerBuysHorse(Player &player, size_t shopHorseIndex);

    bool playerSellsDog(Player &player, size_t playerDogIndex);

    bool playerSellsHorse(Player &player, size_t playerHorseIndex);
};

#endif // SHOP_H
