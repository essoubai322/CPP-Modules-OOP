#pragma once

#include <iostream>
#include <cstring>

class ClapTrap
{
    std::string Name;
    unsigned int Hit_points;
    unsigned int Energy;
    unsigned int AttackDamage;
    public :
        ClapTrap();
        ~ClapTrap();
        ClapTrap(ClapTrap &copy);
        ClapTrap(std::string &other);
        ClapTrap &operator=(ClapTrap &copy);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void Status(void);

};
