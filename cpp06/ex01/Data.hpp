#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    int id;
    std::string name;
    float value;
    
    Data();
    Data(int id, const std::string& name, float value);
};

#endif