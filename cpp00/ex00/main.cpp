#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
    if (ac <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (size_t i = 1; i < (size_t)ac; i++)
            for (size_t j = 0; j < strlen(av[i]); j++)
                std::cout << (char) std::toupper(av[i][j]);
    }
    std::cout << std::endl;
    return (0);

}