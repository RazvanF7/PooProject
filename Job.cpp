//
// Created by razvan on 4/9/25.
//

#include "Job.h"
#include <iostream>
Job::Job(const int salary, const std::string &name, const std::string &description, const int daysTaken) {
    this->salary = salary;
    this->name = name;
    this->description = description;
    this->daysTaken = daysTaken;

}

std::ostream &operator<<(std::ostream &os, const Job &job) {
    os  << "Job: " << job.name
        << "\nSalary: " << job.salary
        << "\nDescription: " << job.description
        << "\nDays to finish: " << job.daysTaken << "\n";
    return os;
}

int Job::getSalary() const {
    return salary;
}
int Job::getDaysTaken() const {
    return daysTaken;
}




