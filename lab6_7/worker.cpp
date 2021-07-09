#include "worker.h"

Worker::Worker() : salary(0) { }

Worker::Worker(std::string f, std::string d, Sex s, const int& p)
    : Person(f, d, s), salary(p) { }

Worker::Worker(std::string f, std::string d, std::string s, const int& p)
    : Person(f, d, s), salary(p) {}

Worker::Worker(Worker&& a) {
    id = a.id;
    fio = std::move(a.fio);
    date = std::move(a.date);
    sex = a.sex;
    salary = a.salary;
}

std::string Worker::Print() const {
    return "Worker " + fio + " " + date + " " + (sex == Sex::FEMALE ? "female" : "male") + " "+ std::to_string(salary);
}
