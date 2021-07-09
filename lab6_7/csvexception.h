#ifndef CSVEXCEPTION_H
#define CSVEXCEPTION_H

#include <string>
#include <exception>
#include <string>
class CSVexception : public std::exception
{
    std::string err;
public:
    CSVexception(const std::string& str) : err(str) { }
    ~CSVexception() { }
    virtual const char* what() const noexcept {return err.c_str(); }
};

#endif // CSVEXCEPTION_H
