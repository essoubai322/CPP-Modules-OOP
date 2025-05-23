#pragma once 
#include <iostream>
#include <cstring>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        std::string getType() const;
        void makeSound() const;
};
