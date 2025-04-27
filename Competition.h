//
// Created by razvan on 4/27/25.
//

#ifndef COMPETITION_H
#define COMPETITION_H
#include <string>
#include <vector>
#include "WeatherCondition.h"


template <typename T>
class Competition {
private:
    std::string country;
    WeatherCondition weather;
    std::vector<const T*> participants;
public:
    Competition(const std::string& country, WeatherCondition weather)
        : country(country), weather(weather) {}

    void addParticipant(const T* animal) {
        participants.push_back(animal);
    }

    const T* simulateRace() const {
        if (participants.empty()) return nullptr;

        // Simulate race based on weather and performance
        const T* winner = participants[0];
        double maxPerformance = 0.0;

        for (const T* animal : participants) {
            double performance = animal->calculatePerformance();
            // Apply weather modifier (e.g., rain reduces performance)
            if (weather == WeatherCondition::Rainy) {
                performance *= 0.8;
            }
            if (performance > maxPerformance) {
                maxPerformance = performance;
                winner = animal;
            }
        }
        return winner;
    }
};



#endif //COMPETITION_H
