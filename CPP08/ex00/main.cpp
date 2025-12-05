#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>


int main()
{
	std::deque<int> vec;
	for (size_t i = 1; i <= 3; i++)
    {
		vec.push_back(i);
        std::cout << "nam : " << i << std::endl;
    }

    for (size_t i = 0; i < vec.size() ; i++)
    {
        std::cout << "s : " << vec[i] << std::endl;
    }
    // vec.push_front(4);
    // try
    // {
    //     int a = easyfind(vec , 4);
    //     std::cout << "Found : " << a << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
}
