#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include "abstarctreader.h"
#include <string>
#include "csvexception.h"

class CSVReader
    : public AbstarctReader
{
    std::ifstream in_;
public:
    CSVReader(const std::string& in);
    bool is_open() const;
    CSVReader& operator>> (Person& obj);
    std::vector<Person> Read();
    operator bool() { return !in_.eof(); }
};


#endif // CSVREADER_H
