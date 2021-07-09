#include "student.h"

Student::Student()
    : mark(0) { }

Student::Student(std::string f, std::string d, Sex s, const int& p)
    : Person(f, d, s), mark(p) { }

Student::Student(std::string f, std::string d, std::string s, const int& p)
    : Person(f, d, s), mark(p) { }

Student::Student(Student&& a) {
    id = a.id;
    fio = std::move(a.fio);
    date = std::move(a.date);
    sex = a.sex;
    mark = a.mark;
}

std::string Student::Print() const {
    return "Student " + fio + " " + date + " " + (sex == Sex::FEMALE ? "female" : "male") + " " + std::to_string(mark);
}
