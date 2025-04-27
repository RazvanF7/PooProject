//
// Created by razvan on 4/9/25.
//

#ifndef WEATHERCONDITION_H
#define WEATHERCONDITION_H

#include "DogBreeds.h"
#include "HorseBreeds.h"


enum class WeatherCondition {
    Sunny,    // No penalty + 20% Arabian
    Rainy,    // -20% performance
    Snowy,    // -30% performance
    Windy,    // -10% performance
    Foggy     // -15% performance
};

double applyWeatherEffect(double performance, WeatherCondition weather,HorseBreed breed);
double applyWeatherEffect(double performance, WeatherCondition weather, DogBreed breed);







#endif
