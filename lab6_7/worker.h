#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person {
    int salary;
public:
    Worker();
    Worker(std::string f, std::string d, Sex s, const int& p);
    Worker(std::string f, std::string d, std::string s, const int& p);
    Worker(const Worker& a) = delete;
    Worker(Worker&& a);
    std::string Print() const;
};

#endif // WORKER_H
