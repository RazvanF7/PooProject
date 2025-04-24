// Shop.cpp

#include "Shop.h"
#include "Player.h"
#include "Dog.h"
#include "Horse.h"
// Add a Dog to the shop's inventory.
void Shop::addDog(const Dog &dog) {
    dogsShop.push_back(dog);
}

// Add a Horse to the shop's inventory.
void Shop::addHorse(const Horse &horse) {
    horsesShop.push_back(horse);
}

// Return the list of Dogs in the shop.
const std::vector<Dog>& Shop::getDogs() const {
    return dogsShop;
}

// Return the list of Horses in the shop.
const std::vector<Horse>& Shop::getHorses() const {
    return horsesShop;
}


bool Shop::playerBuysDog(Player &player, size_t shopDogIndex) {
    if (shopDogIndex >= dogsShop.size())
        return false;

    const Dog &dog = dogsShop[shopDogIndex];
    if (player.getMoney() < dog.getPrice())
        return false;

    player -= dog.getPrice();
    player.addDog(dog);
    dogsShop.erase(dogsShop.begin() + shopDogIndex);
    return true;
}


bool Shop::playerBuysHorse(Player &player, size_t shopHorseIndex) {
    if (shopHorseIndex >= horsesShop.size())
        return false;

    const Horse &horse = horsesShop[shopHorseIndex];
    if (player.getMoney() < horse.getPrice())
        return false;

    player -= horse.getPrice();
    player.addHorse(horse);
    horsesShop.erase(horsesShop.begin() + shopHorseIndex);
    return true;
}


bool Shop::playerSellsDog(Player &player, size_t playerDogIndex) {
    const std::vector<Dog>& playerDogs = player.getDogs();
    if (playerDogIndex >= playerDogs.size())
        return false;

    Dog soldDog = playerDogs[playerDogIndex];

    if (!player.removeDogAtIndex(playerDogIndex))
        return false;

    player += soldDog.getPrice();
    addDog(soldDog);
    return true;
}


bool Shop::playerSellsHorse(Player &player, size_t playerHorseIndex) {
    const std::vector<Horse>& playerHorses = player.getHorses();
    if (playerHorseIndex >= playerHorses.size())
        return false;

    Horse soldHorse = playerHorses[playerHorseIndex];

    if (!player.removeHorseAtIndex(playerHorseIndex))
        return false;

    player += soldHorse.getPrice();
    addHorse(soldHorse);
    return true;
}
