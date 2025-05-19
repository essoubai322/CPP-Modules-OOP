#include "ClapTrap.hpp"

void ClapTrap::Status(void)
{
    std::cout << "Player " << Name << " Status!" << std::endl;
    std::cout << "HP: " << Hit_points << std::endl;
    std::cout << "EP: " << Energy << std::endl;
    std::cout << "AD: " << AttackDamage << std::endl;
}

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10), Energy(10), AttackDamage(0) 
{
	std::cout << "Copy Constructer Default" << std::endl;
}

ClapTrap::ClapTrap(std::string& Name) : Name(Name), Hit_points(10), Energy(10), AttackDamage(0) 
{
	std::cout << "Copy Constructer a Name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) : Name(other.Name), Hit_points(other.Hit_points), Energy(other.Energy), AttackDamage(other.AttackDamage)
{
	std::cout << "Copy Constructer" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap& other)
{
	std::cout << "copy assignment constructor" << std::endl;
        if (this != &other)
        {
            Name = other.Name;
            Hit_points = other.Hit_points;
            Energy = other.Energy;
            AttackDamage = other.AttackDamage;
        }
        return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points > 0 && Energy > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << " , causing " << AttackDamage << " points of damage!" << std::endl;
        Energy--;
    }
    else
        std::cout << "ClapTrap " << Name << " is out of energy or hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_points > 0)
    {
	    std::cout << Name << " it take damage " << amount << " !" << std::endl;
	    if (Hit_points < amount)
		    Hit_points = 0;
        else
	        Hit_points -= amount;
    }
    else
    {
	    std::cout << Name << " is dead !" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points > 0 && Energy > 0)
	{
		std::cout << Name << " Repaired a " << amount << std::endl;
		Energy--;
	}
	else
	{
		std::cout << "ClapTrap " << Name << " is out of energy or hit points!" << std::endl;
	}
}

ClapTrap::~ClapTrap() {
    std::cout << "destructor !" << std::endl;
}
