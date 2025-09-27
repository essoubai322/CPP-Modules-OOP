#include "ScalarConverter.hpp"

enum
{
    INT,
    DOUBLE,
    CHAR,
    FLOAT
};

void ScalarConverter::convert(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
        literal == "-inf" || literal == "+inf" || literal == "nan") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal[0] == '-') {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        return;
    }

    char* end = NULL;
    double d_val = std::strtod(literal.c_str(), &end);
    // std::cout << "val : " << d_val << "\n end : " << end << std::endl;
    if (strlen(end) != 1)
    {
        std::cout << "Error: Invalid input." << std::endl;
        return;
    }
    
    if (end == literal.c_str() || (*end != '\0' && *end != 'f')) 
    {
        if (literal.length() == 1 && !std::isdigit(literal[0]))
        {
            char c_val = literal[0];
            d_val = static_cast<double>(c_val);
        }
        else
        {
            std::cout << "Error: Invalid input." << std::endl;
            return;
        }
    }

    std::cout << "char: ";
    if (std::isnan(d_val) || std::isinf(d_val) || d_val < 0 || d_val > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint((d_val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d_val) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(d_val) || std::isinf(d_val) || d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d_val) << std::endl;
    

    std::cout << "float: " << static_cast<float>(d_val);
    if (!std::isnan(d_val) && !std::isinf(d_val) && d_val == static_cast<int>(d_val))
        std::cout << ".0";
    std::cout << "f" << std::endl;


    std::cout << "double: " << d_val;
    if (!std::isnan(d_val) && !std::isinf(d_val) && d_val == static_cast<int>(d_val))
        std::cout << ".0";
    std::cout << std::endl;
};

int main(int ac, char **av) {
    if (ac != 2) return 1;
    ScalarConverter::convert(av[1]);
}
