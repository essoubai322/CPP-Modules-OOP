#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap();
        ~FragTrap();
        FragTrap(FragTrap &copy);
        FragTrap(std::string &name);
        FragTrap &operator=(FragTrap &copy);
        void attack(const std::string& target);
        void highFivesGuys(void);
};