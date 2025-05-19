#include "ClapTrap.hpp"

int main()
{
    std::string name("Player");
    ClapTrap a(name);
    a.Status();
    a.attack("other player");
    a.takeDamage(20);
    a.takeDamage(20);
    a.beRepaired(5);
    a.Status();
    return (0);
}