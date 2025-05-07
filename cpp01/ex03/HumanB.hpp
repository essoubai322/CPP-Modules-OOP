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
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &newWeapon);
        void attack() const;
};

#endif