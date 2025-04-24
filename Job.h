//
// Created by razvan on 4/9/25.
//

#ifndef JOB_H
#define JOB_H
#include <string>


class Job {
    int salary;
    std::string name;
    std::string description;
    int daysTaken;
    public:
    Job(int salary, const std::string &name, const std::string &description, int daysTaken);

    friend std::ostream &operator<<(std::ostream &os, const Job &job);

    int getSalary() const;
    int getDaysTaken() const;
};





#endif //JOB_H
