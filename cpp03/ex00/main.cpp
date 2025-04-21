#include <iostream>
#include <cstring>

class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;
public:
    ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {}
    ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {}
    ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {}
    ClapTrap& operator=(const ClapTrap& other)
    {
        if (this != &other)
        {
            name = other.name;
            hitPoints = other.hitPoints;
            energyPoints = other.energyPoints;
            attackDamage = other.attackDamage;
        }
        return *this;
    }
    ~ClapTrap() {}
    void setName(const std::string& name) { this->name = name; }
    std::string getName() const { return name; }
    unsigned int getHitPoints() const { return hitPoints; }
    unsigned int getEnergyPoints() const { return energyPoints; }
    unsigned int getAttackDamage() const { return attackDamage; }
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is out of energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Hit points left: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is already out of hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! Hit points now: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " is out of energy or hit points!" << std::endl;
    }
}

int main()
{
    ClapTrap claptrap1("CLTP1");
    ClapTrap claptrap2("CLTP2");

    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(claptrap1.getAttackDamage());

    claptrap2.beRepaired(5);
    claptrap1.takeDamage(3);

    return 0;
}
