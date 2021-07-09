#include "csvreader.h"

using namespace std;

namespace CSVR {
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
}

CSVReader::CSVReader(const std::string& in) : in_(in) {
}

 bool CSVReader::is_open() const {
     return in_.is_open();
 }

 std::vector<Person> CSVReader::Read() {
     vector<Person> mas;
     //try {
         string str;
         Person::InitSize();
         while (getline(in_, str)) {
             if (str == "")
                 continue;
             vector<string> v = CSVR::split(str, ';');
             int id = std::stoi(v[0]);
             if (v[3] != "male" && v[3] != "female")
                 throw CSVexception("Sex is wrong");
             if (v.size() > 4)
                 throw CSVexception(to_string(mas.size() + 1) + ' ' + "invalid value");
             mas.push_back(Person(v[1], v[2], v[3] == "female" ? Sex::FEMALE : Sex::MALE));
         }
    /*
     }  catch (CSVexception& err) {
         std::cout << err.what() << endl;
     } catch (std::exception& err) {
         std::cout << "Id is wrong." << endl;
     }
    */
     return mas;
 }

 CSVReader& CSVReader::operator>>(Person& obj) {
     if (in_.eof())
         return *this;
     std::string buff;
     getline(in_, buff);
     if (buff == "")
         return *this;
     std::vector<std::string> mas = CSVR::split(buff, ';');
     obj = Person(mas[1], mas[2], mas[3]);
     return *this;
 }
