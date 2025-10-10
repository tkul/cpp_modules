#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data {
    int id;
    std::string name;
    float value;
    
    Data();
    Data(const Data& other);
    Data(int id, const std::string& name, float value);
    Data& operator=(const Data& other);
    ~Data();
};

#endif