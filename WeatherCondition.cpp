//
// Created by razvan on 4/9/25.
//

#include "WeatherCondition.h"

double applyWeatherEffect(double performance, WeatherCondition weather, const std::string& breed) {
    switch (weather) {
        case WeatherCondition::Rainy:
            if (breed == "Mustang" || breed == "Greyhound") {
                return performance*1.2;
            }
            return performance * 0.8;
        case WeatherCondition::Snowy:
            if (breed=="Icelandic" || breed=="Husky") {
                return performance*1.2;
            }
            return performance * 0.7;

        case WeatherCondition::Windy:
            if (breed=="American" || breed=="Border Collie") {
                return performance*1.2;
            }
            return performance * 0.9;
        case WeatherCondition::Foggy:
            if (breed=="Arabian" || breed=="German Shepard") {
                return performance*1.2;
            }
            return performance * 0.85;
        case WeatherCondition::Sunny:
            if (breed=="Spanish" || breed=="Dalmatian") {
                return performance*1.2;
            }
            return performance;
        default:
            return performance;
    }
}
