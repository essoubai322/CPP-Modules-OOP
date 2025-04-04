#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class HumanB
{
    private :
        std::string name;
        Weapon *weapon;
    public :
        HumanB(std::string name) : name(name), weapon(NULL) {}
        ~HumanB() {}
        void setWeapon(Weapon &newWeapon)
        {
            weapon = &newWeapon;
        }
        void attack() const
        {
            if (weapon)
                std::cout << name << " attacks with their " << weapon->getType() << std::endl;
            else
                std::cout << name << " has no weapon to attack with!" << std::endl;
        }
};

#endif