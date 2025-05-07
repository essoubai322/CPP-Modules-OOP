#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include <cstring>
#include "Weapon.hpp"
class HumanA
{
    private :
        std::string name;
        Weapon &weapon;
    public :
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack() const;
};
#endif