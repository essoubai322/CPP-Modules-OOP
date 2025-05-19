#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ~ScavTrap();
        ScavTrap(ScavTrap &copy);
        ScavTrap(std::string &name);
        ScavTrap &operator=(ScavTrap &copy);
        void attack(const std::string& target);
        void guardGate();
};
