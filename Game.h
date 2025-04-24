//
// Created by razvan on 4/11/25.
//

#ifndef GAME_H
#define GAME_H
#include "Animal.h"
#include "Horse.h"
#include "Dog.h"
#include "Player.h"


class Game {
    const int difficulty;
    const int days;
public:
    Game(int difficulty, int days);

    void run();
};



#endif //GAME_H
