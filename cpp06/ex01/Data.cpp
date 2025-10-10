# include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0f) {}

Data::Data(const Data& other) : id(other.id), name(other.name), value(other.value) {}

Data::Data(int id, const std::string& name, float value) : id(id), name(name), value(value) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        value = other.value;
    }
    return *this;
}

Data::~Data() {}