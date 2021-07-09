#ifndef BOSS_H
#define BOSS_H

#include "person.h"

class Boss : public Person {
    int hard;
public:
    Boss();
    Boss(std::string f, std::string d, Sex s, const int& p);
    Boss(std::string f, std::string d, std::string s, const int& p);
    Boss(const Boss& a) = delete;
    Boss(Boss&& a);
    std::string Print() const;
};

#endif // BOSS_H
