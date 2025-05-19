#include "ScavTrap.hpp"

int main()
{
    std::string name("APA");
    ScavTrap a(name);
    a.attack("3abass");
    a.beRepaired(10);
    a.guardGate();
    a.Status();
    return (0);
}