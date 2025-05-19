#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap Constructer Default" << std::endl;
    this->Hit_points = 100;
    this->Energy = 100;
    this->AttackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "ScarTrap destructor !" << std::endl;
}

FragTrap::FragTrap(FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constructer" << std::endl;
}

FragTrap::FragTrap(std::string &name) : ClapTrap(name)
{
    this->Hit_points = 100;
    this->Energy = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap Constructer with parameters" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &copy)
{
    std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy > 0)
    {
        std::cout << "FragTrap " << Name << " attacks " << target << " , causing " << AttackDamage << " points of damage!" << std::endl;
        Energy--;
    }
    else
        std::cout << "FragTrap " << Name << " is out of energy or hit points!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->Name << " says: DRBNI YDI LYDIK!" << std::endl;
}
