#include "WeatherCondition.h"
#include "HorseBreeds.h"
#include "DogBreeds.h"

// Overload for horses
double applyWeatherEffect(double performance, WeatherCondition weather, HorseBreed breed) {
    switch (weather) {
        case WeatherCondition::Rainy:
            return (breed == HorseBreed::Mustang) ? performance * 1.2 : performance * 0.8;
        case WeatherCondition::Snowy:
            return (breed == HorseBreed::American) ? performance * 1.2 : performance * 0.7;
        case WeatherCondition::Windy:
            return (breed == HorseBreed::American) ? performance * 1.2 : performance * 0.9;
        case WeatherCondition::Foggy:
            return (breed == HorseBreed::Arabian) ? performance * 1.2 : performance * 0.85;
        case WeatherCondition::Sunny:
            return (breed == HorseBreed::Spanish) ? performance * 1.2 : performance;
        default:
            return performance;
    }
}

// Overload for dogs
double applyWeatherEffect(double performance, WeatherCondition weather, DogBreed breed) {
    switch (weather) {
        case WeatherCondition::Rainy:
            return (breed == DogBreed::Greyhound) ? performance * 1.2 : performance * 0.8;
        case WeatherCondition::Snowy:
            return (breed == DogBreed::GermanShepherd) ? performance * 1.2 : performance * 0.7;
        case WeatherCondition::Windy:
            return (breed == DogBreed::BorderCollie) ? performance * 1.2 : performance * 0.9;
        case WeatherCondition::Foggy:
            return (breed == DogBreed::GermanShepherd) ? performance * 1.2 : performance * 0.85;
        case WeatherCondition::Sunny:
            return (breed == DogBreed::Dalmatian) ? performance * 1.2 : performance;
        default:
            return performance;
    }
}