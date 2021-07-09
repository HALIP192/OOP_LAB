#include "personcsv.h"


using namespace std;

PersonCsv::PersonCsv() {}

std::vector<string> split(std::string& str, char pass) {
    std::vector<string> v;
    size_t start = 0, end = str.find(pass, start);
    while (end != std::string::npos) { // string::npos = -1
        end = str.find(pass, start);
        v.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    return v;
}

PersonCsv::PersonCsv(const std::string& in, const std::string& out) {
    if (out != "")
        out_.open(out, std::ios_base::app);
    if (in != "")
        in_.open(in);
}

 bool PersonCsv::in_is_open() {
     return in_.is_open();
 }

 bool PersonCsv::out_is_open() {
     return out_.is_open();
 }

 std::ofstream& PersonCsv::operator<< (const Person& elem) {
     elem.fprint(out_, ';');
     out_ << endl;
     return out_;
 }

 std::vector<Person> PersonCsv::read() {
     vector<Person> mas;
     string str;
     Person::InitSize();
     while (getline(in_, str)) {
         vector<string> v = split(str, ';');
         mas.push_back(Person(v[1], v[2], v[3] == "female" ? Sex::FEMALE : Sex::MALE));
     }
     return mas;
 }

 void PersonCsv::output(std::vector<Person>& mas) {
     for (size_t i = 0; i < mas.size(); i++) {
         out_ << i + 1 << ';';
         mas[i].fprint(out_, ';');
         out_ << endl;
     }
 }

