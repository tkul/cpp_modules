#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) { (void)other; return *this; }
Serializer::~Serializer() {}

Data::Data() : id(0), name(""), value(0.0f) {}
Data::Data(const Data& other) : id(other.id), name(other.name), value(other.value) {}
Data::Data(int id, const std::string& name, float value) : id(id), name(name), value(value) {}
Data::~Data() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}