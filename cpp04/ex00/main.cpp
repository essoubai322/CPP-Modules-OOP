#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal *i = new Cat();
    std::cout << "type j : " <<  j->getType() << " " << std::endl;
    std::cout << "type i : " << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    // const WrongAnimal *k = new WrongCat();
    // std::cout << "type k : " << k->getType() << " " << std::endl;
    // k->makeSound();
    // delete k;
    delete meta;
    delete i;
    delete j;
    return 0;
}