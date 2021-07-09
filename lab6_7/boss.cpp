#include "boss.h"

Boss::Boss()
    : hard(0) { }

Boss::Boss(std::string f, std::string d, Sex s, const int& p)
    : Person(f, d, s), hard(p) { }

Boss::Boss(std::string f, std::string d, std::string s, const int& p)
    : Person(f, d, s), hard(p) { }

Boss::Boss(Boss&& a) {
    id = a.id;
    fio = std::move(a.fio);
    date = std::move(a.date);
    sex = a.sex;
    hard = a.hard;
}

std::string Boss::Print() const {
    return "Boss" + fio + " " + date + " "+ (sex == Sex::FEMALE ? "female" : "male") + " " + std::to_string(hard);
}
