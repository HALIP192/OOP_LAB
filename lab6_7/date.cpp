#include <date.h>

Date::Date(const uint d, const uint m, const uint y) : day(d), month(m), year(y) {}

Date::Date(const std::string& time) {
    try {
        day = std::stoi(time.substr(0, 2));
        month = std::stoi(time.substr(3, 2));
        year = std::stoi(time.substr(6));
    } catch (std::exception& a) {
        std::cout << "Date was input no correctly." << std::endl;
    }
}
void Date::set(uint d, uint m, uint y) {
    day = d;
    month = m;
    year = y;
}
uint Date::get_day() {
    return day;
}
uint Date::get_month() {
    return month;
}
uint Date::get_year() {
    return year;
}
