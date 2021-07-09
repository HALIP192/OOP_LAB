#ifndef PERSONCSV_H
#define PERSONCSV_H

#include <person.h>
#include <fstream>
#include <iostream>
#include <vector>

class PersonCsv {
    std::ifstream in_;
    std::ofstream out_;
public:
    PersonCsv();
    PersonCsv(const std::string& in, const std::string& out);
    bool in_is_open();
    bool out_is_open();
    std::ifstream& operator>> (Person& elem);
    std::ofstream& operator<< (const Person& elem);
    std::vector<Person> read();
    void output(std::vector<Person>& mas);
};

#endif // PERSONCSV_H
