#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
    int mark;
public:
    Student();
    Student(std::string f, std::string d, Sex s, const int& p);
    Student(std::string f, std::string d, std::string s, const int& p);
    Student(const Student& a) = delete;
    Student(Student&& a);
    std::string Print() const;
};

#endif // STUDENT_H
