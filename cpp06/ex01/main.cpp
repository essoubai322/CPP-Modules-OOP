#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() 
{
    Data* originalPtr = new Data;
    originalPtr->s1 = "Hello";
    originalPtr->n = 42;
    originalPtr->s2 = "World";

    std::cout << "orginal ptr : " << originalPtr << std::endl;
    std::cout << "check inside ptr :     \ns1=\"" << originalPtr->s1 
              << "\", n=" << originalPtr->n 
              << ", s2=\"" << originalPtr->s2 << "\"" << std::endl;
    std::cout << std::endl;
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized to uintptr_t: " << raw << std::endl;
    std::cout << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized Pointer Addr: " << deserializedPtr << std::endl;
    std::cout << "Deserialized Data content: s1=\"" << deserializedPtr->s1 
              << "\", n=" << deserializedPtr->n 
              << ", s2=\"" << deserializedPtr->s2 << "\"" << std::endl;
    std::cout << std::endl;
    std::cout << "CHECK IF SAME ADD OR NOT? \nanswer : ";

    if (deserializedPtr == originalPtr) {
        std::cout << "SAME!" << std::endl;
    } else {
        std::cout << "NOOOOOOOO!" << std::endl;
    }
    
    // Clean up the memory allocated with 'new'.
    delete originalPtr;

    return 0;
}