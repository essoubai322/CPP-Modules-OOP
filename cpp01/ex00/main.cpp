#include "Zombie.hpp"

int main()
{
    Zombie cat;
    randomChump("APA");
    Zombie* dog = newZombie("dog");
    cat.announce();
    dog->announce();
    delete dog;
    return 0;
}
