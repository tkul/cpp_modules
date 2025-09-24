#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data originalData(42, "Hello World", 3.14f);
    Data* originalPtr = &originalData;
    
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << originalPtr << std::endl;
    std::cout << "ID: " << originalData.id << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "\n=== Serializer ===" << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "\n=== Deserialized Data ===" << std::endl;
    std::cout << "Address: " << deserializedPtr << std::endl;
    std::cout << "ID: " << deserializedPtr->id << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Value: " << deserializedPtr->value << std::endl;
    
    // Test equality
    std::cout << "\n=== Comparison ===" << std::endl;
    std::cout << "Original pointer == Deserialized pointer: " 
              << (originalPtr == deserializedPtr ? "TRUE" : "FALSE") << std::endl;
    
    std::cout << "Data values match: " 
              << (originalPtr->id == deserializedPtr->id && 
                  originalPtr->name == deserializedPtr->name && 
                  originalPtr->value == deserializedPtr->value ? "TRUE" : "FALSE") << std::endl;
    
    return 0;
}