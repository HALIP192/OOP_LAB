#include <person.h>

using namespace std;

int Person::size_ = 0;

Person::Person() {}

Person::Person(std::string f, std::string d, Sex s) : id(GetID()), fio(f), date(d), sex(s) {}

Person::Person(std::string f, std::string d, std::string s) : id(GetID()), fio(f), date(d), sex(s == "female" ? Sex::FEMALE : Sex::MALE) {
}

Person::Person(Person&& a) {
    id = a.id;
    fio = std::move(a.fio);
    date = std::move(a.date);
    sex = a.sex;
}

void Person::fprint(std::ofstream& out, const char& pass) const {
    out << id << pass + fio + pass + date + pass + (sex == Sex::FEMALE ? "female" : "male");

}

void Person::print(std::ostream& out) const {
    out << id << " " +  fio + " " + date + " " + (sex == Sex::FEMALE ? "female" : "male");
}

bool Person::operator==(const Person& a) const {
    if (fio == a.fio && date == a.date && sex == a.sex)
        return 1;
    return 0;
}

void Person::operator=(Person&& a) {
    id = a.id;
    fio = std::move(a.fio);
    date = std::move(a.date);
    sex = a.sex;
}


bool Person::operator<(Person& a) const {
    Date one(date);
    Date two(a.date);
    if (one.get_year() < two.get_year())
        return 1;
    else {
        if (one.get_year() == two.get_year() && one.get_month() < two.get_month())
            return 1;
        else {
            if (one.get_month() == two.get_month() && one.get_day() < two.get_day())
                return 1;
        }
    }
    return 0;
}

std::ostream& operator<<(std::ostream& out, const Person& obj) {
    out << obj.Print();
    return out;
}
