#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// i->makeSound();
	j->makeSound();
	delete j;
	// delete i;
	// const Cat *a =  new Cat();
	// Cat *b = new Cat();
	// *b = *a;

	// b->makeSound();
	// std::cout << b->getType() << std::endl;
	// delete b;
	// delete a;
	return 0;
}
