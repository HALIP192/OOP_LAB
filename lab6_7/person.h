#ifndef PERSON_H
#define PERSON_H

//#include <date.h>
#include <string>
#include <iostream>
#include <fstream>
#include "date.h"

enum Sex { FEMALE, MALE };

class Person {
    static int size_;
    static int GetID() { return ++size_; }

protected:
    int id;
    std::string fio;
    std::string date;
    Sex sex;
public:

    Person();
    Person(std::string f, std::string d, Sex s);
    Person(std::string f, std::string d, std::string s);
    Person(const Person& a)= delete;
    Person(Person& a) = delete;
    Person(Person&& a);
    void fprint(std::ofstream& out, const char& pass) const;
    void print(std::ostream& out) const;
    virtual std::string Print() const { return "Person " + fio + " " + date + " " + (sex == Sex::FEMALE ? "female" : "male"); };
    bool operator<(Person& a) const;
    std::string GetYear() const { return date.substr(date.size() - 4, 4); }
    std::string GetFIO() const { return fio; }
    int GetId() const { return id; }
    bool operator==(const Person& a) const;
    void operator=(Person&& a);
    void operator=(Person&a) = delete;
    static void InitSize() { size_ = 0; }
};

std::ostream& operator<<(std::ostream&, const Person&);


#endif // PERSON_H
