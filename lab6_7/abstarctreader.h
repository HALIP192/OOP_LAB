#ifndef ABSTARCTREADER_H
#define ABSTARCTREADER_H

#include "person.h"
#include <vector>
#include "string"
#include <iostream>

class AbstarctReader
{
public:
    virtual std::vector<Person> Read() = 0;
    virtual bool is_open() const = 0;
    virtual ~AbstarctReader() = default;
    virtual AbstarctReader& operator>>(Person&) = 0;
    virtual operator bool() = 0;
};


#endif // ABSTARCTREADER_H
