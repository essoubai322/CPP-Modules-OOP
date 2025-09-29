#include "Base.hpp"

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
    int random_choice = std::rand() % 3;
    switch (random_choice)
    {
        case 0:
            std::cout << "generating A..." << std::endl;
            return new A();
        case 1:
            std::cout << "generating B..." << std::endl;
            return new B();
        case 2:
            std::cout << "generating C..." << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    std::cout << "--- chkon nta ? ---" << std::endl;
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Nta howa : A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Nta howa : B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Nta howa : C" << std::endl;
    } else {
        std::cout << "Ma3rftsh chkon nta!" << std::endl;
    }
}

int main() {
    std::srand(time(NULL));
    Base *random_object_ptr = generate();

    if (random_object_ptr) {
        identify(random_object_ptr);
        delete random_object_ptr;
    } else {
        std::cerr << "Generation failed." << std::endl;
    }

    std::cout << "\n--- Explicit Test ---" << std::endl;
    A a_obj;
    identify(&a_obj);

    return 0;
}