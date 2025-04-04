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
        HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}
        ~HumanA() {}
        void attack() const
        {
            std::cout << name << " attacks with their " << weapon.getType() << std::endl;
        }
};
#endif