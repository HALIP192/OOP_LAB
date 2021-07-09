#ifndef JSONREADER_H
#define JSONREADER_H


#include "abstarctreader.h"
#include "json.hpp"
#include <stdexcept>
#include <exception>
#include <iostream>
#include "csvexception.h"

class JSONReader
        : public AbstarctReader
{
private:
    std::ifstream in_;
    nlohmann::json json;
    void input() { in_ >> json; }
public:
    JSONReader(const std::string& name) : in_(name) {}
    bool is_open() const { return in_.is_open(); }
    std::vector<Person> Read();
    JSONReader& operator>>(Person&);
    operator bool() { return !in_.eof(); }
};

#endif // JSONREADER_H
