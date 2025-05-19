#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap Constructer Default" << std::endl;
    this->Hit_points = 100;
    this->Energy = 50;
    this->AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScarTrap destructor !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructer" << std::endl;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name)
{
    this->Hit_points = 100;
    this->Energy = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap Constructer with parameters" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &copy)
{
    std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << " , causing " << AttackDamage << " points of damage!" << std::endl;
        Energy--;
    }
    else
        std::cout << "ScavTrap " << Name << " is out of energy or hit points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate Keeper mode!" << std::endl;
}