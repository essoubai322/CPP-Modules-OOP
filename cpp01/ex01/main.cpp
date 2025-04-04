#include "Zombie.hpp"

int main()
{
	Zombie *Hord = zombieHorde(3, "apa");

	for (int i = 0; i < 3; i++)
		Hord[i].announce();
	delete[] Hord;
	return 0;
}