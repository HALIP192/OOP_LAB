#include "jsonreader.h"

/*

[
        {"id": 0, "name": "Prokopev", "year": "22.22.22", "year": "male"},
        {"id": 1, "name": "Kalinin", "color": "12.15.13", "sex": "male"}
]

*/

void from_json(const nlohmann::json& j, Person& obj)
{
	std::string a, b, c, d;
    j.at("id").get_to(a);
    j.at("name").get_to(b);
    j.at("date").get_to(c);
    j.at("sex").get_to(d);
    obj = Person(b, c, d);
}

std::vector<Person> JSONReader::Read() {
     std::vector<Person> mas;
    //try {
        if (!json.size()) {
            input();
        }
        for (auto& e: json) {
            auto c = e.get<Person>();
            mas.push_back(std::move(c));
        }
        return mas;
    /*}  catch (std::exception& e) {
        std::cout << "Wrong in file." << std::endl;
    }
    return mas;
    */
}

JSONReader& JSONReader::operator>>(Person& obj){
    return *this;
}
