#pragma once 

# include <iostream>

class Brain
{
    std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);   
};