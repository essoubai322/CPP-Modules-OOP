#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "default";
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}
