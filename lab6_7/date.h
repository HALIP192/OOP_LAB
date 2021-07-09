#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>
#include <exception>
#include <iostream>
typedef unsigned int uint;

class Date {
    uint day, month, year;
public:
    Date(const uint d = 0, const uint m = 0, const uint y = 0);
    Date(const std::string& time);
    void set(uint d, uint m, uint y);
    uint get_day();
    uint get_month();
    uint get_year();
};

#endif // DATE_H




